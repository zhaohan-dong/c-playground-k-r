// reverse polish expression from command line
// use push and pop for stack mgmt, as inspired by solutions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void push(double f);
double pop(void);


int main(int argc, char *argv[]) {
    int c, type;
    double result;
    while (--argc > 0) {
        *++argv;
        if (!isdigit(c = **argv) && strlen(*argv) == 1) {
            type = c;
        } else {
            type = 0;
        }
        switch (type) {
            case '+':
                printf("h");
                push(pop() + pop());
                break;
            case '-':
                push(- pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                push(1 / pop() * pop());
                break;
            case 0:
                printf("num");
                push(atof(*argv));
                break;
        }
    }
    result = pop();
    printf("%g\n", result);
    return 0;
}



#define STACK_SIZE 4

int stack_height = 0;
double stack[STACK_SIZE];

void push(double f) {
    if (stack_height < STACK_SIZE) {
        stack[stack_height++] = f;
    } else {
        printf("Error: stack full\n");
    }
}

double pop(void) {
    if (stack_height > 0) {
        return stack[stack_height--];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}