/*
Exercise 2-5. Write the function any(s1,s2), which returns the first 
location in a string s1 where any character from the string s2 occurs, 
or -1 if s1 contains no characters from s2. (The standard library 
function strpbrk does the same job but returns a pointer to thelocation.)
*/
#include <stdio.h>

unsigned int any(char*s1, char*s2){
    // assume s1 and s2 are null-terminated
    unsigned int i = 0, j = 0, s1_in2_s2 = 0;
    for (i = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                s1_in2_s2 = 1;
            }
        }
        if (s1_in2_s2) break;
    }
    return i;
}

int main(){
    char* s1 = "oapsieaflksdhf;asdjf";
    char* s2 = "kzzebwrbfd";
    printf("%s,%s: %u", s1, s2, any(s1, s2));
    return 0;
}