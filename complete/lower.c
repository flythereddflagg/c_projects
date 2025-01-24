/*
Exercise 2-10. Rewrite the function lower, which converts upper 
case letters to lower case, with a conditional expression instead of if-else.
*/
#include <stdio.h>

#define MAX_LEN 512
#define LOWER_DIST 32

void lower(char* str){
    for (int i = 0; str[i] != '\0' && i < MAX_LEN; i++){
        printf("%c->", str[i]);
        str[i] = 
            (str[i] >=  'A' && str[i] <= 'Z') ? 
            str[i] + LOWER_DIST : 
            str[i];
        printf("%c, ", str[i]);
    }
    printf("\n");
}

int main(){
    char str1[MAX_LEN] = {"CHeeEEeeeZE"};
    char str2[MAX_LEN] = {"sladkfjasd;fl"};
    char str3[MAX_LEN] = {";fl74598437259087\\][\\][]"};
    lower((char*) str1); 
    lower((char*) str2); 
    lower((char*) str3);
    printf("%s, %s, %s\n", str1, str2, str3);
    return 0;
}
