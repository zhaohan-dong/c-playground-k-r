/* page 24 convert input to lower */

#include<stdio.h>
#include <ctype.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}