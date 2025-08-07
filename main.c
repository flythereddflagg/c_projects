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
#define LINE_LEN 80

typedef enum {false, true} bool;

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

void parse_line(char* line, int line_len, Stack* stk){
    char op[MAXOP] = "\0";
    int oplen = 0;
    for (int i = 0; i < line_len; i++){
        if (line[i] == EOF){
            line[line_len-1] = EOF;
            return;
        }
        if (line[i] == '\n'){
            printf(" \\n\n");
            break;
        }
        else
            printf(" %c", line[i]);
        // if (line[i] == ' '){
        //     if (oplen == 0) 
        //         continue;
        //     oplen ++;
        //     op[oplen] = '\0';
        //     oplen = 0;
        //     execute_op(&op[0], stk);
        //     continue;
        // }
        // op[oplen] = line[i];
        // oplen ++;
    }
    // if (oplen){

    // }
}

int main(int argc, char** argv){
    Stack stk_var = Stack_init();
    Stack* stk = &stk_var;
    char line_arr[LINE_LEN];
    char* line = &(line_arr[0]);
    bool running = true;

    while (running){
        printf("--%u--\n", EOF);
        fgets(line, LINE_LEN, stdin);
        parse_line(line, LINE_LEN, stk);
        if (line[LINE_LEN - 1] == EOF) 
            running = false;
    }
    return 0;
}
