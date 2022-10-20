#include<stdio.h>

/* page 19 */

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '-')
            putchar('\n');
        else
            putchar(c);
    }
    return 0;
}