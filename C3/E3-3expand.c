/* exercise 3-3 expands(s1, s2) that expands shorthand notations like a-z in s1 to list abc...xyz in s2
    handle cases like a-b-c a-z0-9 and -a-z */

#include<stdio.h>
#include<ctype.h>

int expand(char * s1, char * s2);

int main(void)
{
    char s1[256] = "a-c1-5 1256-9", s2[256];
    int r;
    r = expand(s1, s2);
    printf("%s\nReturn code: %d\n", s2, r);
    return r;
}

int expand(char * s1, char * s2)
{
    int i, j, k;
    j = 0;

    for (i = 0; s1[i] != '\0'; ++i) {
        // if i is start of shorthand (if s1[i] is alphanumeric and the following space is -)
        if (isalnum(s1[i]) && (s1[i+1] == '-')) {
            
            // if i and i+2 is are same type, else throw error
            if ((isalpha(s1[i]) && isalpha(s1[i+2])) || (isnumber(s1[i]) && isnumber(s1[i+2]))) {

                // parse s1[i] to s2[j] (start of sequence)
                s2[j] = s1[i];

                while (s2[j] != s1[i+2]) {
                    // determine if the sequence in s1 increases or decreases
                    s2[++j] = s2[j] + ((s1[i] < s1[i+2])? 1 : -1);
                }
                ++i;
            } else {
                // throw error because s1[i] and s1[i+2] are not same type
                return -1;
            }
        } else {
            // not shorthand start, pass on s1[i] to s2[j] and increase j for next iteration (i increased at for-loop)
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
    return 0;
}