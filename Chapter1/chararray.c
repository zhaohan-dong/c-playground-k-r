/* page 26 character array find longest line */

#define MAXLINE 1000 /* maximum input line size */

int main() { /* find longest line */
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line, saved */
    
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(line, save);
        }
    if (max > 0) /* there was a line */
        printf("%s", save);
}

int getline(s, lim)
char s[];
int lim;
{
    
}