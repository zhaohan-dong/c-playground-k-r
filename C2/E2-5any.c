/* any(s1,s2) that returns first index in s1 where any char from s2 occurs, or -1 if doesn't contain any*/

#include<stdio.h>

int any(char s1[], char s2[]);

int main(void) {
    int loc;
    loc = any("Hello world", "od");
    printf("%d\n", loc);
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;
    int firstloc = -1; // set default return to -1

    for(i = 0; s1[i] != '\0'; ++i) { // loop through every position of s1
        for(j = 0; s2[j] != '\0' && firstloc == -1; ++j) { // loop through s2 for each location
            if (s1[i] == s2[j])
                firstloc = i; // match found and updates first loc
        }
    }

    return firstloc;
}