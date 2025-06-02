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
#include <string.h>
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

int Stack_push(Stack* self, double val){
    
    if ((*self).top + 1 >= STACK_LEN){
        printf("Error: Stack is full\n");
        return -1;
    }
    (*self).top++;
    (*self).arr[(*self).top] = val;
    //printf("pushing %f", val);
    return 0;
}

double Stack_pop(Stack* self){
    if ((*self).top < 0){
        printf("Error: Stack is empty\n");
        return 0.0;
    }
    double popped = (*self).arr[(*self).top];
    (*self).top--;
//    printf("popping %f", popped);

    return popped;
}

char getop(char* s){
    // loads the operator/operand into s and returns the type in the string
    char type = (s[0] >= '0' && s[0] <= '9')? NUMBER : s[0];
    return type;
}

void get_line(char** line){
    char c = '\0';
    char word[MAXOP];
    int index = 0, j = 0;
    while((c = getchar()) != '\n'){
        if(index >= (MAXOP - 1) || c == ' '){
            word[index] = '\0';
            strncpy(word, line[j], index);
            j++;
            index = 0;
            continue;
        }
        word[index] = c;
        index++;
    }

    word[index] = '\0';
    strncpy(word, line[j], index);
    line[j+1] = "\n";
}

int main(int argc, char** argv){
    Stack stk = Stack_init();
    Stack* stk_p = &stk;
    char* ops[MAXOP];
    char** pops = &ops[0];
    char op_type = '\0';
    char* p_op_str;
    get_line(pops);
    for(int j = 0; j < MAXOP; j++){
        for (int i = 0; i < MAXOP; i++){
            p_op_str = ops[i];
            op_type = getop(p_op_str);
            switch (op_type){
                case NUMBER:
                    Stack_push(stk_p, atof(p_op_str));
                    break;
                case '+':
                    Stack_push(
                        stk_p, 
                        Stack_pop(stk_p) + Stack_pop(stk_p)
                    );
                case '\n':
                case '\r':
                    printf("output: %f\n", Stack_pop(stk_p));
                    break;
                default:
                    printf("Unknown operand type '%d' -> '%s'", (int) op_type, p_op_str);
            }
            if (p_op_str[0] == '\n') 
                break;
        }
    }
    return 0;
}
