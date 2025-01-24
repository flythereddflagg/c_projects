#include <stdio.h>
#include <ctype.h>

#define NBINS 128

int main(){
    int chars[NBINS];
    int c = 0, i = 0;
    for (c = 0; c < NBINS; c++) chars[c] = 0;

    while ((c = getchar()) != EOF){
        chars[c]++;
    }
    for (c = 0; c < NBINS; c++){
        if (!chars[c]) continue;
        if (isprint(c)) printf(" '%2c': ", c);
        else printf("'\\%03d': ", c);
        for (i = 0; i < chars[c]; i++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

