/*
Program to create a histogram with the number of letters in each word given
*/
#include <stdio.h>

#define NBINS 10

int main(){
    int c = 0, wordlen = 0, i = 0;
    int data[NBINS];
    for (i = 0; i < NBINS; i++) data[i] = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t') {
            if (wordlen > 0 && wordlen - 1 < NBINS){
                ++data[wordlen - 1];
            } else if (wordlen >= NBINS - 1) {
                ++data[NBINS - 1];
            }
            wordlen = 0;
        } else {
            ++wordlen;
        }
    }
    for (c = 0; c < NBINS; c++){
        printf("%2d (%d): ", c+1, data[c]);
        for (i = 0; i < data[c]; i++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

