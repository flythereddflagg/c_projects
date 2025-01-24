#include <stdio.h>
#include "dbg.h"

int main(int argc, char *argv[])
{
    FILE* file = fopen("data.csv", "w");
    fprintf(file, "2,3,4,5,\n");
    fprintf(file, "3,4,5,6,\n");
    check(fclose(file) == 0, "FILE ERROR OCCURED");
    
    FILE* filer = fopen("data.csv", "r");
    char ch = ' ';
    printf("\n");
    while (ch != EOF){
        ch = fgetc(filer);
        printf("%c", ch);
    }
    check(fclose(filer) == 0, "FILE ERROR OCCURED");
    
    return 0;
    
error:
    return 0;
}