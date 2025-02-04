/*
Exercise 3-2. Write a function escape(s,t) that converts characters 
like newline and tab into visible escape sequences like \n and \t as 
it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters. 
*/
#include <stdio.h>
#include "dbg.h"

void escape(char* src, char* dest){
    int offset = 0, i = 0;
    for (i = 0; src[i] != '\0'; i++){
        switch (src[i]){
            case '\n':
                dest[i+offset] = '\\';
                offset ++;
                dest[i+offset] = 'n';
                break;
            case '\t':
                dest[i+offset] = '\\';
                offset ++;
                dest[i+offset] = 't';
                break;
            default:
                dest[i+offset] = src[i];
                break;
        }
    }
    dest[i+offset] = '\0';
}

void un_escape(char* src, char* dest){

}


int main(){
    char in[30] = "the\n quick brown\t fox\n!";
    char out[30];
    printf("'%s'\n", out);
    escape(&(in[0]), &(out[0]));
    printf("escape--> '%s'\n", out);
    return 0;
}
