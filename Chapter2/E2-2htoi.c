/* page 42 htoi(s) */

#include<stdio.h>
#include<ctype.h>

int htoi(s)
char s[];
{
    int i, n; // n output number
    n = 0;
    for (i = 0;
            (s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'a' && s[i] <= 'f') || 
            (s[i] >= 'A' && s[i] <= 'F');
            ++i) {
                n = 16 * n; // move right one digit
                if (s[i] >= '0' && s[i] <= '9') { // case digit
                    n = n + s[i] - '0';
                } else if (s[i] >= 'a' && s[i] <= 'f') { // case lowercase
                    n = n + s[i] - 'W';
                } else {
                    n = n + s[i] - '7';
                }
            }
    return n;
}

int main() {
    int c, i = 0;
    char arr;
    int d;
    while ((c = getchar()) != EOF && i < 256) {
        arr[i++] = c;
    }
    d = htoi(arr);
    printf("%d\n", d);
}

