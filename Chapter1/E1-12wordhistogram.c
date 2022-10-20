#include<stdio.h>

/* page 22 */

int main() {
    int c, i, j, wordcount;
    int wordlen[256];
    for (i = 0; i < 256; ++i)
        wordlen[i] = 0;
    
    wordcount = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '-' )
            ++wordcount;
        else
            ++wordlen[wordcount];
    }

    printf("Word length histogram:\n");
    for (i = 0; i < wordcount; ++i) {
        for (j = 0; j < wordlen[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}