/*
Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent. 
*/

#include <stdio.h>
#include <ctype.h>

 /* atof: convert string s to double */
 double atof(char s[]){
    double val, power, exp;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    for (exp = 0.0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');
    for (int j = 0; j < exp; j++)
        val *= 10.0;


    return sign * val / power;
 }

 int main(){
    char test1[] = "1.223049"; 
    printf("%s: %f\n", test1, atof(test1));
    char test2[] = "1.223049e2"; 
    printf("%s: %f\n", test2, atof(test2));
    return 0;
}