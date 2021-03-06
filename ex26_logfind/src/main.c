/* -- logfind.main.c --
find strings in files in the ~/.logfind directory

Instructions:
I want a tool called logfind that lets me search through log files for text. 
This tool is a specialized version of another tool called grep, but designed 
only for log files on a system. The idea is that I can type:

$ logfind zedshaw

And, it will search all the common places that log files are stored, and print 
out every file that has the word “zedshaw” in it.
The logfind tool should have these basic features:
 1. This tool takes any sequence of words and assumes I mean “and” for them. 
    So logfind zedshaw smart guy will find all files that have zedshaw and smart 
    and guy in them.
 2. It takes an optional argument of -o if the parameters are meant to be or 
    logic.
 3. It loads the list of allowed log files from ~/.logfind.
 4. The list of file names can be anything that the glob function allows. Refer 
    to man 3 glob to see how this works. I suggest starting with just a flat 
    list of exact files, and then add glob functionality.
 5. You should output the matching lines as you scan, and try to match them as 
    fast as possible.
That’s the entire description. Remember that this may be very hard, so take it 
a tiny bit at a time. Write some code, test it, write more, test that, and 
so on in little chunks until you have it working. Start with the simplest thing 
that gets it working, and then slowly add to it and refine it until every 
feature is done.
*/
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_LINE_LEN 150

struct flist{
    char** files;
    int len;
};

struct flist get_list()
{
    int i;
    struct flist lglst;
    lglst.len = 0;
    FILE* rfile = fopen(".logfind", "r");
    check(rfile, "File not found!");
    
    char ch = ' ';  // make sure that ch != EOF    
    
    while (ch != EOF){
        ch = fgetc(rfile);
        if (ch == '\n') lglst.len++;
    }
    
    rewind(rfile);
    ch = ' ';
    char* line  = malloc(MAX_LINE_LEN * sizeof(char));
    char** flst = malloc(lglst.len * sizeof(char*));
    for (i = 0; i < lglst.len; i++){
        flst[i] = malloc(MAX_LINE_LEN * sizeof(char));
    }

    int lsi = 0;
    int li  = 0;
    while (ch != EOF){
        ch = fgetc(rfile);
        if (ch == '\n'){
            strncpy(flst[lsi], line, MAX_LINE_LEN);
            lsi++;
            li = 0;
            for (i = 0; i < MAX_LINE_LEN; i++){
                line[i] = '\0';
            }
        }
        else {
            line[li] = ch;
            li++;
        }
    }
    
    lglst.files = flst;
    free(line);
    return lglst;

error:
    return lglst;
}



int check_file(char* filename, char* word, unsigned int wordlen)
{
    FILE* rfile = fopen(filename, "r");
    check(rfile, "File not found!");
    
    char ch = ' ';  // make sure that ch != EOF    
    int wi = 0, look = 0;
    
    while (ch != EOF){
        // get a char
        ch = fgetc(rfile);
        // if you see the first letter start looking for the rest
        if (ch == word[0]) look = 1;
        // check if you have found the next letter in the word
        if (wi < wordlen && ch == word[wi] && look) wi++;
        // otherwise you reset the word index and stop looking for the word
        else {
            wi = 0;
            look = 0;
        }
        // if you have found a sufficient number of correct letters you have
        // found the word
        if (wi == wordlen) return 1;
    }
    check(fclose(rfile) == 0, "Error with file.");
    return 0;
    
error:
    return -1;
}

int print_file_hits(char* filename, char* word, unsigned int wordlen)
{
    FILE* rfile = fopen(filename, "r");
    check(rfile, "File not found!");
    
    char line[MAX_LINE_LEN];
    
    char ch = ' ';  // make sure that ch != EOF
    
    int line_number = 1, // initalize line_number to 1
        li          = 0, // line index
        wi          = 0, // word index
        look        = 0, // bool; if look == 1 we have found the first letter
        found       = 0, // bool; found the word on a line
        infile      = 0; // bool; returns number of hits in file
    
    while (ch != EOF){
        // get a char
        ch = fgetc(rfile);
        // if it fits add the char to the line array
        if (li < MAX_LINE_LEN && ch != '\n') line[li++] = ch;
        // if you see the first letter start looking for the rest
        if (ch == word[0]) look = 1;
        // check if you have found the next letter in the word
        if (wi < wordlen && ch == word[wi] && look) wi++;
        // otherwise you reset the word index and stop looking for the word
        else {
            wi = 0;
            look = 0;
        }
        // if you have found a sufficient number of correct letters you have
        // found the word
        if (wi == wordlen) found = 1;
        // print results and reset everything when you find a new line
        if (ch == '\n') {
           if (found){
               infile += 1;
               printf("Found in file \"%s\" On line %d:\n", filename, line_number);
               printf("\t\"%s\"\n", line);
               found = 0;
           }
           // reset line
            for (li = 0; li < MAX_LINE_LEN; li++) {
                line[li] = '\0';
            }
           li = 0;
           wi = 0;
           line_number ++; 
        }
    }
    check(fclose(rfile) == 0, "Error with file.");
    return infile;
    
error:
    return -1;
}


int and_check(char* filename, int argc, char* argv[]){
    printf("\nAND Searching file: \"%s\"...\n", filename);
    int i, out = 0;
    for (i = 1; i < argc; i++){
        out = check_file(filename, argv[i], strlen(argv[i]));
        if (!out){
            printf("No results.\n");
            return 0;
        }
        check(out != -1, "Error with file check");
    }
    for (i = 1; i < argc; i++){
        out = print_file_hits(filename, argv[i], strlen(argv[i]));
        printf("Found \"%s\" %d times.\n\n", argv[i], out);
        check(out != -1, "Error with file hit print");
    }
    return 1;

error:
    return -1;
}

int or_check(char* filename, int argc, char* argv[]){
    printf("\nOR Searching file: \"%s\"...\n", filename);
    int i, out = 0;
    for (i = 1; i < argc; i++){
        if (!strcmp(argv[i],"-o")) continue;
        out = print_file_hits(filename, argv[i], strlen(argv[i]));
        printf("Found \"%s\" %d times.\n\n", argv[i], out);
        check(out != -1, "Error with file hit print");
    }
    return 1;

error:
    return -1;
}

int main (int argc, char* argv[])
{
    char* fname;
    int out, i, or_logic = 0;
    
    struct flist lglst = get_list();
    
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i],"-o")){
            or_logic = 1;
            break;
        }
    }
    for (i = 0; i < lglst.len; i++){
        fname = lglst.files[i];
        if (or_logic) out = or_check(fname, argc, argv);
        else out = and_check(fname, argc, argv);
        check(out != -1, "ERROR 1")
    }
    for (i = 0; i < lglst.len; i++){
        if (lglst.files[i]) free(lglst.files[i]);
    }
    if (lglst.files) free(lglst.files);
    return 0;

error:
    free(lglst.files);
    return -1;
}