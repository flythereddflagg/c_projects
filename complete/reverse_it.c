#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int len);

int main(){
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0){
        printf("%d ", len);
        reverse(line, len);
        printf("%s\n", line);

        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) printf("%s", longest);
    return 0;
}

int getline(char s[], int lim){
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}

void reverse(char line[], int len){
    int i = 0;
    char tmp = 0;
    for (i = 0; i < (len/2); i++){
        tmp = line[len-i-1];
        line[len-i-1] = line[i];
        line[i] = tmp;
    }
}

