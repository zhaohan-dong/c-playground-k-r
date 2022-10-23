/* E3-5 itob(n,s,b) that converts the integer n into a base b character representation in the string s. */

#include<stdio.h>
#include <string.h>
#include "reverse.c"

int itob(int n, char s[], int b) {
    int i, remainder;

    for (i = 0; n != 0; ++i) {
        // go through the int from lower to higher digits, the remainder is the digit
        remainder = n % b;
        if (remainder < 10) {
            // digit less than 11 (numbers)
            s[i] = (char) (remainder + 48);
        } else {
            // digit greater than 11 (alphabet required)
            s[i] = (char) (remainder + 55);
        }
        n = (n - remainder) / b;
    }
    reverse(s);
    s[++i] = '\0';
    return 0;
}

int main(void) {
    char out[256];
    itob(15697, out, 16);
    printf("%s\n", out);
}