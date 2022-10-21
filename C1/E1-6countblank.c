#include<stdio.h>

/* page 18 */

int main() {
    int c, bc, tc, nl; // Char, blank, tab and newline count
    bc = tc = nl = 0;


    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++bc;
        if (c == '\t')
            ++tc;
        if (c == '\n')
            ++nl;
    }
    printf("Blank: %d, Tab: %d, Newline: %d\n", bc, tc, nl);
    return 0;
}