/* page 31 entab - replace blank spaces with minimum number of tabs and blank*/

#include<stdio.h>
#include<math.h>

int main() {
    int c, i, spacelen = 0, inspace = 0;
    int n = 8; // tab equal to n number of spaces

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && !inspace) // if current char is not space and was not in space before
            putchar(c);
        else if (c != ' ') { // if current char is not space, but follows space before
            for (i = 0; i <= floor(spacelen / n); ++i) { // index to spacelen / n + 1 numbers of tabs
                putchar('\t');
            }
            if (spacelen % n != 0) // cannot be fully divided
                for (i = 0; i < spacelen % n; ++i) { // modulus of spacelen / n loops of space to fill up the rest
                    putchar(' ');
                }
            putchar(c);
            inspace = 0;
            spacelen = 0;
        }
        else {
            inspace = 1; // we're in space set inspace flag
            spacelen = spacelen + 1;
        }
    }
}