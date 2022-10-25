/* exercise 4-11 getop without ungetch */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define NUMBER '0'

int getch(void);
int getop(char s[]);

char buf[BUFSIZE];  /* buffer for ungetch */
int  bufp = 0;      /* next free position in buf */

int main(void) {
    int result;
    char c[] = "5321-2506";
    result = getop(c);
    return 0;
}

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    static char buf = EOF;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
        if (buf == EOF || buf == ' ' || buf == '\t') {
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
    } else
        c = buf;
    if (!isdigit(c) && c != '.')
        return c;     /* not a number */
    i = 0;
    if (isdigit(c))   /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')     /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf = c;
    return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
