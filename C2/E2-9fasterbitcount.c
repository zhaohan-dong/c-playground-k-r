/* E2-9 faster bit count */

#include<stdio.h>

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}

int main(void)
{
    int x = 0xC;
    printf("%d\n", bitcount(x));
    return 0;
}