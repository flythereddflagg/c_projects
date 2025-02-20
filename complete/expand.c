/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand 
notations like a-z in the string s1 into the equivalent complete 
list abc...xyz in s2. Allow for letters of either case and digits, 
and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
Arrange that a leading or trailing - is taken literally.
*/
#include <stdio.h>
#include "dbg.h"

void expand(char* s1, char* s2){
    int offset = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        printf("i = %d, %c, %d\n", i, s1[i], offset);
        switch (s1[i]){
            case '-':
            // case '\0':
                char range_lo = s1[i-1], range_hi = s1[i+1];
                
                //invalid range just; continue on
                if (range_lo > range_hi || 0 == i){ 
                    s2[i + offset] = s1[i];
                    break;
                }
                offset --;
                for (char j = range_lo; j <= range_hi; j++){
                    printf("(-in) i = %d, %c, %d\n", i, j, i+offset);
                    s2[i+offset] = j;
                    offset ++;
                }
                offset -= 2;

                break;

            default:
                printf("(default) i = %d, %c, %d\n", i, s1[i], offset);
                s2[i + offset] = s1[i];
                break;
        }
    }
}

int main(){
    char s1[500] = "-adf<A-s>dfa<a-b-c>w<0-9>er(9-0)ewrw---";
    char s2[500] = "";
    expand((char*) &s1[0], (char*) &s2[0]);
    printf("'%s', '%s'", s1, s2);
    return 0;
}
