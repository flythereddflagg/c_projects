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

int check_file(char* filename, char* word, unsigned int wordlen)
{
    FILE* filer = fopen(filename, "r");
    int out;
    char ch = ' ';
    while (ch != EOF){
        ch = fgetc(filer);
        if (ch == word[0]){
            int i;
            for (i = 1; i < wordlen; i++) {
                ch = fgetc(filer);
                if (ch != word[i]) break;
            }
            if (i == wordlen) out = 1;
            else out = 0;
        }
    }
    check(fclose(filer) == 0, "File Not Found.");
    return out;
    
error:
    return -1;
}


int main (int argc, char* argv[])
{
    char* ts = argv[1];
    unsigned int tslen = strlen(ts);
    char* fname = "dat.log";
    int out = check_file(fname, ts, tslen);    
    printf("test %d\n", tslen);
    printf("%d\n", out);
    check(out != -1, "Error with file check");
    return 0;

error:
    return -1;
}