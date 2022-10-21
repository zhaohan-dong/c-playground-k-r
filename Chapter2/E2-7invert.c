/* exercise 2-7 invert(x,p,n) invert n bits that begin at position p inverted */

#include<stdio.h>

int invert(unsigned int x, unsigned int p, unsigned int n);

int main(void) {
    unsigned x;
    int p, n;

  for(x = 0; x < 700; x += 49)
    for(n = 0; n < 8; n++)
      for(p = 0; p < 8; p++)
        printf("%x, %d, %d: %x\n", x, p, n, invert(x, p, n));
}

int invert(unsigned int x, unsigned int p, unsigned int n) {
  return x ^ (~(~0U << n) << p) ;
}