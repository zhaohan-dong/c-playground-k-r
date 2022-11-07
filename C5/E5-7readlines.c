// readlines storing lines in array instead of calling alloc
#include <stdio.h>
#include "getline.c"
#include "alloc.c"
#include "readlines.c"
#define MAXLEN 1000   /* max length of any input line */
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines);
int readlines2(char lines[][MAXLEN], int maxlines);

int main() {
	
}


/* readlines:  read input lines */
int readlines2(char lines[][MAXLEN], int maxlines)
{
	int len, nlines;

	nlines = 0;
	while ((len = getline(lines[nlines], MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else {
			lines[nlines++][len-1] = '\0'; /* delete newline */
		}
	return nlines;
}
