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



int main(){
    int t1 = 0b10000000000000000000000000000000;
    char s[90] = "";
    itoa(t1, s);
    printf("%d : '%s'\n", t1, s);
    return 0;
}
