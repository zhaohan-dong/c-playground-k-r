/* strend(s,t) returns 1 if string t occurs at the end of string s, and 0 otherwise */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main() {
    char *a = "the world is over";
    char *b = "over";
    printf("%d\n", strend(a, b));
    return 0;
}

int strend(char *s, char *t) {
    s += (strlen(s) - strlen(t));
    while (*s++ == *t++) {
        if (*s == '\0')
            return 1;
    }
    return 0;
}