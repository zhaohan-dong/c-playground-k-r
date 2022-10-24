/* exercise 4-1 strrindex(s,t), which returns the position of the rightmost occurence of t in s, or -1 if there is none */

#include <stdio.h>

int strrindex(char s[], char t) {
    int i, j;
    j = -1;

    for (i = 0; s[i] != '\0' && s[i] != EOF; ++i) {
        if (s[i] == t) {
            j = i;
        }
    }

    return j;
}

int main(void) {
    int i;
    i = strrindex("Hello world", 'l');
    printf("The index is: %d\n", i);
    return 0;
}