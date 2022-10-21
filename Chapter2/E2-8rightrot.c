/* exercise 2-8 right rotate rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions*/

#include<stdio.h>

unsigned int rightrot(unsigned x, int n);

int main(void)
{
	unsigned int x = 4105;
	int n = 8;

	unsigned int r = rightrot(x, n);
    printf("result: %u\n", r);
	return 0;
}

unsigned int rightrot(unsigned x, int n) {
    while (n > 0) {
        if ((x & 1) == 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        --n;
    }
    return x; // x >> n returns left part to the right, and x << (sizeof(x) - n) returns right part to the right
}