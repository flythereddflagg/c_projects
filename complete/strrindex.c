/*
Exercise 4-1. Write the function strindex(s,t) which returns the position 
of the rightmost occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(){
    char line[MAXLINE];
    char to_index = 'g';
    while (getline(line, MAXLINE) > 0){
        printf("found at --> %d\n", strrindex(line, to_index));
    }
    return 0;
}

/* getline: get line into s, return length */
int getline(char s[], int lim){
    int c, i;
    i = 0;
    printf("in --> ");
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]){
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t){
    int len = 0;
    while (s[len++] != '\0');
    len --;
    for (; len > -1; len--){
        if(s[len] == t)
            break;
    }
    return len;
}
