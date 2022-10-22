/* exercise 3-3 expands(s1, s2) that expands shorthand notations like a-z in s1 to list abc...xyz in s2
    handle cases like a-b-c a-z0-9 and -a-z */

#include<stdio.h>
#include<ctype.h>

int expand(char * s1, char * s2);

int main(void)
{
    char s1[256] = "a-c", s2[256];
    int r;
    r = expand(s1, s2);
    printf("%s\nReturn code: %d\n", s2, r);
    return 0;
}

int expand(char * s1, char * s2)
{
    int i, j, k;
    j = 0;

    for (i = 0; s1[i] != '\0'; ++i) {

        // if i is start of shorthand
        if (isalnum(s1[i]) && (s1[i+1] == '-')) {
            
            // if i and i+2 is are same type
            if ((isalpha(s1[i]) && isalpha(s1[i+2])) || (isnumber(s1[i]) && isnumber(s1[i+2]))) {

                // parse s1[i] to s2[j] (start of sequence)
                s2[j] = s1[i];

                while (s2[j] != s1[i+2]) {
                    // determine if the sequence in s1 increases or decreases
                    s2[++j] = s2[j] + (s1[i] < s1[i+2]) ? 1 : -1;
                }
            } else {
                return -1;
            }
        } 
    }
    return 0;
}