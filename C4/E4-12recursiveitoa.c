/* E4-12 a recursive version of itoa */

#include <stdio.h>
#include <limits.h>

#define MAXSTRING 1000

void itoa(int n, char s[]) {
    static int i;
    static int sign = 0;

    if (sign == 0) {
        sign = (n < 0) ? -1 : 1;
        n = n * sign;
        i = 0;
    }

    if (n / 10) {
        itoa(n / 10, s);
    }

    if (sign != 0)
    {
        if (sign < 0)
            s[i++] = '-';
        sign = 0;
    }

    s[i] = n % 10 + '0';
    s[++i] = '\0';
}

int main() {
    int i;
    char s[MAXSTRING];
    int array[22] =
        {   0,
            1,
            2,
            9,
            10,
            11,
            16,
            17,
            21,
            312,
            -0,
            -1,
            -2,
            -9,
            -10,
            -11,
            -16,
            -17,
            -21,
            -312,
            INT_MAX,
            INT_MIN,
            };
     for (i = 0; i < 22; ++i)
    {
        itoa(array[i], s);
        printf("%d    %s\n", array[i], s);
    }
    return 0;
}
