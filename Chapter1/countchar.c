#include<stdio.h>

/* page 6 */

int main() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}