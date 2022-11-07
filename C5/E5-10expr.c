// reverse polish expression from command line
// use push and pop for stack mgmt, as inspired by solutions

#include <stdio.h>
#include <string.h>

void push(double f);
double pop(void);

int main(int argc, char *argv[]) {
    while (--argc > 0) {
        *++argv;
    }
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