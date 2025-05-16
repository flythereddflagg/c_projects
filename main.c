/*
Pre EX 4-3: IMPLEMENT THE POLISH CALCULATOR WITH A STACK
Exercise 4-3. Given the basic framework, it's straightforward to extend the 
calculator. Add themodulus (%) operator and provisions for negative numbers. 
Exercise 4-4. Add the commands to print the top elements of the stack without 
popping, toduplicate it, and to swap the top two elements. Add a command to 
clear the stack. 
Exercise 4-5. Add access to library functions like sin, exp, and pow. See 
<math.h> in Appendix B, Section 4. 
Exercise 4-6. Add commands for handling variables. (It's easy to provide 
twenty-six variableswith single-letter names.) Add a variable for the most 
recently printed value. 
Exercise 4-7. Write a routine ungets(s) that will push back an entire string 
onto the input.Should ungets know about buf and bufp, or should it just use 
ungetch? 
Exercise 4-8. Suppose that there will never be more than one character of 
pushback. Modify getch and ungetch accordingly. 
Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. 
Decidewhat their properties ought to be if an EOF is pushed back, then 
implement your design. 
Exercise 4-10. An alternate organization uses getline to read an entire input 
line; this makesgetch and ungetch unnecessary. Revise the calculator to use 
this approach.
*/


#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 100
#define NUMBER 1
#define MAXOP 30

typedef struct {
    int top;
    double arr[STACK_LEN];
} Stack;

int Stack_push(Stack self, double val){
    if (self.top < STACK_LEN){
        self.top++;
        self.arr[self.top] = val;
        return self.top;
    }
    printf("\nerror: stack full, can't push %f\n", val);
    return -1;
}

double Stack_pop(Stack self){
    if (self.top > 0){
        return self.arr[self.top--];
    }
    printf("\nerror: stack empty\n");
    return 0.0;
}

int getop(char* s){
    char c;
    int i = 0;
    while ((c = getchar()) != ' '){
        printf("%c", c);
        if (i >= MAXOP) 
            break;
        s[i] = c;
        i++;
    }
    if (s[0] >= '0' && s[0] <= '9')
        return NUMBER;
    else
        return s[0];
}


 int main(int argc, char** argv){
    int type;
    double op2;
    char ss[MAXOP];
    char* s = &ss[0];
    Stack math_stack;
    math_stack.top = -1;
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                Stack_push(math_stack, atof(s));
                break;
            case '+':
                Stack_push(math_stack, Stack_pop(math_stack) + Stack_pop(math_stack));
                break;
            case '*':
                Stack_push(math_stack, Stack_pop(math_stack) * Stack_pop(math_stack));
                break;
            case '-':
                op2 = Stack_pop(math_stack);
                Stack_push(math_stack, Stack_pop(math_stack) - op2);
                break;
            case '/':
                op2 = Stack_pop(math_stack);
                if (op2 != 0.0)
                    Stack_push(math_stack, Stack_pop(math_stack) / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
            case '\r':
                printf("\toutput: %f\n", Stack_pop(math_stack));
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
        float toppy_toppins = Stack_pop(math_stack);
        printf("top: %f\n", toppy_toppins);
        Stack_push(math_stack, toppy_toppins);
    }
    return 0;
}
