/* E4-13 recursive version of reverse(s), which reverses string s in place */

#include <stdio.h>
#include <string.h>

int reverse(char s[]) {
    static int i = 0;
    static int j;
    int c;

    // initializes the end index at first level
    if (i == 0)
        j = strlen(s) - 1;

    // swap characters
    c = s[i];
    s[i] = s[j];
    s[j] = c;

    // indices close in to the middle
    ++i;
    --j;

    // exit when reaches middle, else do recursive
    if (j - i < 1) {
        return 0;
    }
    reverse(s);
}

int main() {
    char str[] = "Hello wor ld!";
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
}