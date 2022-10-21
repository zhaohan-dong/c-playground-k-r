/* page 31 detab - replace tab with blank spaces*/

#include<stdio.h>

int main() {
    int c, i;
    int n = 6; // tab equal to n number of spaces
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            for (i = 0; i < n; ++i)
                putchar(' ');
        else
            putchar(c);
    }
}