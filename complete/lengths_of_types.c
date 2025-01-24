#include <stdio.h>
typedef char u8;
typedef signed char i8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef long double f128;



int main(){
    printf("char %lld bits\n", 8 * sizeof(char));
    printf("short %lld bits\n", 8 * sizeof(short));
    printf("int %lld bits\n", 8 * sizeof(int));
    printf("long %lld bits\n", 8 * sizeof(long));
    printf("long long %lld bits\n", 8 * sizeof(long long));
    printf("float %lld bits\n", 8 * sizeof(float));
    printf("size_t %lld bits\n", 8 * sizeof(size_t));
    printf("double %lld bits\n", 8 * sizeof(double));
    printf("long double %lld bits\n", 8 * sizeof(long double));
    printf("--> '%c' char\n", 128);
    return 0;
}
