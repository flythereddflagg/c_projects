// write function htoi(s) which takes a hexadecimal string 's' and converts
// it to an int
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char* s);

int main(){
    char* tests[] = {
        "0x012345",
        "0x0fff36",
        "0x000334",
        "0123467",
        "67",
        "0X034ts567",
        "0X034567",
        "pp0X034ts567",
    };
    for (int i = 0; i < 8; i++){
        printf("%s :", tests[i]);
        printf(" %d\n", htoi(tests[i]));
    }
    return 0;
}


int htoi(char* s){
    // assume all strings are null terminated
    int i = 0, output = 0, digit_val = 0;
    
    for (
        i = 0;
        (s[i] >= '0' && s[i] <= '9') || 
        (s[i] >= 'a' && s[i] <= 'f') ||
        (s[i] >= 'A' && s[i] <= 'F') ||
        s[i] == 'x' || s[i] == 'X';
        i++
    ){
        if (s[i] == 'x' || s[i] == 'X' || (s[i] == '0' && i == 0)) continue;
        digit_val = (
            (s[i] >= '0' || s[i] <= '9') ? 
            ((int) s[i] - '0') : 
            ((int) tolower(s[i]) - 'a')
        );
        output = 16 * output + digit_val;
        // printf("%c, %d, %d, %d\n", s[i], i, digit_val, output);

    }
    return output;

}