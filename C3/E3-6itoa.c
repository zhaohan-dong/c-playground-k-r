/* E3-6 alternative version of itoa that accepts three arguments, third arugment minimum field width and padded on left with blanks */

#include <stdio.h>
#include "reverse.c"

int itoa(int n, char s[], int l) {
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < l) {
        s[i++] = 32;
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n, l;
    char s[256];
    n = -14256;
    l = 16;
    itoa(n, s, l);
    printf("%s\n", s);
    return 0;
}