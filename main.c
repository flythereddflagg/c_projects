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
#define NUMBER '1'
#define MAXOP 30

typedef struct {
    int top;
    double arr[STACK_LEN];
} Stack;

Stack Stack_init(){
    Stack new_stack;
    new_stack.top = -1;
    return new_stack;
}

int Stack_push(Stack self, double val){
    if (self.top + 1 >= STACK_LEN){
        printf("Error: Stack is full\n");
        return -1;
    }
    self.top++;
    self.arr[self.top] = val;
    printf("pushing %f", val);
    return 0;
}

double Stack_pop(Stack self){
    if (self.top < 0){
        printf("Error: Stack is empty\n");
        return 0.0;
    }
    double popped = self.arr[self.top];
    self.top--;
    printf("popping %f", popped);

    return popped;
}

char getop(char* s){
    // loads the operator/operand into s and returns the type in the string
    char c = '\0';
    int index = 0;
    char type;
    while (c != ' ' && c != '\n'){
        c = getchar();
        if (index >= MAXOP - 1){
            index = MAXOP - 1;
            break;
        }
        s[index] = c;
        index ++;
    }
    s[index] = '\0';
    type = (s[0] >= '0' && s[0] <= '9')? NUMBER : s[0];
    if (c == '\n' && type != EOF)
        type = '\n';
    return type;
}

int main(int argc, char** argv){
    char op_type;
    char op_str[MAXOP];
    char* p_op_str = &(op_str[0]);
    Stack math_stack = Stack_init();
    while ((op_type = getop(p_op_str)) != EOF){
        // printf("%c -> %s\n", op_type, p_op_str);
        switch (op_type){
            case NUMBER:
                // push atof(p_op_str)
                Stack_push(math_stack, atof(p_op_str));
                break;
            case '+':
                // push(pop() + pop())
                Stack_push(
                    math_stack, 
                    Stack_pop(math_stack) + Stack_pop(math_stack)
                );
            case '\n':
            case '\r':
                printf("output: %f\n", Stack_pop(math_stack));
            default:
                printf("Unknown operand type '%c' -> '%s'", op_type, p_op_str);
        }
    }
    return 0;
}
