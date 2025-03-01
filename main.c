/*
Exercise 3-4. In a two's complement number representation, our version 
of itoa does not handle the largest negative number, that is, the value of n 
equal to -(2wordsize-1). Explain why not. Modify it to print that value 
correctly, regardless of the machine on which it runs. 

Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a 
base b character representation in the string s. In particular, itob(n,s,16) 
formats s as a hexadecimal integer in s. 

Exercise 3-6. Write a version of itoa that accepts three arguments instead of 
two. The third argument is a minimum field width; the converted number must be 
padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include "dbg.h"

void space_pad(char s[], int n){
    if (n < 0) return;
    // pad on the left with spaces
    // assume there is sufficient space in array to move it
    for (int i = 0; i < n; i++){
        int len = 0;
        while (s[len++] != '\0');
        for(int j = len+1; j > 0; j--){
            s[j] = s[j+1];
        }
        s[0] = ' ';
    }
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
/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;
    unsigned int n2;
    if ((sign = n) < 0) /* record sign */
        n2 = (unsigned int) -n; /* make n positive */
    else
        n2 = (unsigned int) n;
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n2 % 10 + '0'; /* get next digit */
    } while ((n2 /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}

void itob(int n, char s[], char b){
    int i, sign;
    unsigned int n2;
    if ((sign = n) < 0) /* record sign */
        n2 = (unsigned int) -n; /* make n positive */
    else
        n2 = (unsigned int) n;
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n2 % b + '0'; /* get next digit */
        if (s[i-1] > '9') 
            s[i-1] += 7;
    } while ((n2 /= b) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
}

void more_itoa(int n, char s[], int width){
    int len = 0;
    while (s[len++] != '\0');
    itoa(n, s);
    space_pad(s, len - width);

}

int main(){
    // 3-4 solution
    // this occurs because a postivie integer only goes up to max val - 1
    // to fix use and unsigned int
    printf("3-4\n");
    int t1 = 0b10000000000000000000000000000000;
    char s[90] = "";
    itoa(t1, s);
    printf("%d : '%s'\n", t1, s);

    // 3-5 solution
    int to_convert = 485;
    s[0] = '\0'; // reset string
    printf("3-5\n");

    itob(to_convert, s, 2);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 2, s);
    to_convert++;
    itob(to_convert, s, 4);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 4, s);
    to_convert++;
    itob(to_convert, s, 8);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 8, s);
    to_convert++;
    itob(to_convert, s, 10);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 10, s);
    to_convert++;
    itob(to_convert, s, 16);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 16, s);
    to_convert++;
    itob(to_convert, s, 36);
    printf("%d convert to base: %02d: '%s'\n", to_convert, 36, s);

    // 3-6 solution
    s[0] = '\0'; // reset string
    printf("3-6\n");
    more_itoa(t1, s, 30);
    printf("%d : '%s'\n", t1, s);

    return 0;
}
