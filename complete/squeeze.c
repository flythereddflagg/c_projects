/*
Write a function "squeeze(s1, s2)" that deletes each character in s1 
that matches any character in the string s2
*/
#include <stdio.h>


void squeeze(char* s1, char* s2, char* out){
    // assume for now that s1 and s2 are null terminated
    
    int len1 = 0, len2 = 0, i = 0, j = 0, offset = 0;
    char cur = s1[len1];
    int add_it = 1;


    for (i = 0; s1[i] != '\0'; i++){
        add_it = 1;
        for (j = 0; j < len2; j++){
            if (s1[i] == s2[j]){
                add_it = 0;
                break;
            }
            
        }
        if (add_it){
            out[offset] = s1[i];
            offset ++;
        }
    }
    out[offset] = '\0';
}

int main(){
    char* s1 = "I new a man once who didn't care what people thought of him.";
    char* s2 = "aeiou";
    char out_string[1024];
    printf("-->'%s' : '%s'\n", s1, s2);
    squeeze(s1, s2, (char*) &out_string);
    printf("-->'%s'\n", out_string);

    return 0;
}