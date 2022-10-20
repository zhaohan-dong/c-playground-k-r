/* page 46 get n bits from left to right at position p 
    for example, x = 100 (1100100), p = 2, n = 4 returns 9 (1001)

*/
#include<stdio.h>

int getbits(x, p, n)
unsigned x, p, n;
{
    return (x >> p & ~(~0 << n) );
}

int main() {
    int c, x, p, n;
    int field; // field tracks which one of the x, p, n field is being filled
    x = p = n = field = 0;

    while((c = getchar()) != EOF) {
        if(c != ' ' && c != '\t' && c != '\n') {
            switch (field)
            {
            case 0: // enter x
                x = 10 * x + c - '0';
                break;
            case 1: // enter p
                p = 10 * p + c - '0';
                break;
            case 2: // enter n
                n = 10 * n + c - '0';
                break;
            default:
                break;
            }
        } else {
            if (x && p) // if x and p has been entered before space
                field = 2; // fill n
            else if (x) // if x has been filled
                field = 1; // fill p
        }
    }
    printf("%u\n", getbits(x, p, n));
    return 0;
}

