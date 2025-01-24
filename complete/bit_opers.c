/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the
n bits that begin at position p set to the rightmost n bits of y, 
leaving the other bits unchanged.

Exercise 2-7. Write a function invert(x,p,n) that returns x with 
the n bits that begin at position p inverted (i.e., 1 changed into 
0 and vice versa), leaving the others unchanged. 

Exercise 2-8. Write a function rightrot(x,n) that returns the value of 
the integer x rotated to the right by n positions.
*/
#include <stdio.h>

#define BYTE_LEN 8
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 


typedef char u8;

void print_byte(char x){
    printf(BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(x));
}

char setbits(char x, u8 p, u8 n, char y){
    char mobile = 1, setter = 0;
    u8 i = 0;
    for (i = 0; i < n-1; i++){
        // print_byte(mobile);
        mobile = mobile << 1;
        mobile = mobile + 1;
        
    }
    setter = mobile;
    mobile = mobile & y;
    mobile = mobile << (BYTE_LEN - p - n);
    setter = setter << (BYTE_LEN - p - n);
    // invert setter
    setter = ~ setter;
    x = x & setter;
    x = x | mobile;

    return x;
}

char invert(char x, u8 p, u8 n){
    const char copy_x = x;
    u8 i = 0;
    char setter = 1;
    for (i = 0; i < n-1; i++){
        setter = setter << 1;
        setter = setter + 1;
        
    }
    setter = setter << (BYTE_LEN - p - n);
    x = x & ~setter; // erase the bits to be inverted
    x = x | (~(copy_x & setter) & setter); // copy the inverted bits back in
    return x;
}

char rightrot(char x, u8 n){
    const char set_one = 1, set_left = 128;
    char right_is_true = 0;

    for (int i = 0; i < n; i++){
        right_is_true = x & set_one; //check if rightmost bit is true or false
        x = x >> 1;
        x = x & ~set_left; // ensure leftmost bit is 0
        if (right_is_true)
            x = x | set_left; // set the leftmost bit to true
    }
    
    return x;
}

int main(){
    // 2-6
    char x = 13, y = 11;
    u8 p = 0, n = 4;
    char out = setbits(x, p, n, y);
    printf("2-6: "
        BYTE_TO_BINARY_PATTERN", %u, %u, "
        BYTE_TO_BINARY_PATTERN" = "
        BYTE_TO_BINARY_PATTERN"\n",
        BYTE_TO_BINARY(x), p, n, BYTE_TO_BINARY(y), 
        BYTE_TO_BINARY(out)
    );

    // 2-7
    x = 245;
    p = 1;
    n = 4;
    out = invert(x, p, n);
    printf("2-7: "
        BYTE_TO_BINARY_PATTERN", %u, %u = "
        BYTE_TO_BINARY_PATTERN"\n",
        BYTE_TO_BINARY(x), p, n, 
        BYTE_TO_BINARY(out)
    );

    // 2-7
    x = 135;
    n = 3;
    out = rightrot(x, n);
    printf("2-7: "
        BYTE_TO_BINARY_PATTERN", %u = "
        BYTE_TO_BINARY_PATTERN"\n",
        BYTE_TO_BINARY(x), n, 
        BYTE_TO_BINARY(out)
    );


    return 0;
}