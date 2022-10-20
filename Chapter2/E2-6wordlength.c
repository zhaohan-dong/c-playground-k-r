/* page 46 get word length */
#include<stdio.h>

int wordlength()
{
    int num = -1; // character to measure length
    int len = 0; // length
    unsigned int num_copy = (unsigned int)num;
    while (num_copy >>= 1) {
        ++len;
    }
    return len + 1;
}



int main() {
    printf("%d\n", wordlength());
    return 0;
}