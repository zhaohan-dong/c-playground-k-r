#include<stdio.h>

int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
        c = getchar();
    }
    return 0;
}