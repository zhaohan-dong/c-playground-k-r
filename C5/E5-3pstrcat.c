/* pointer version of strcat */

#include <stdio.h>
#define STR_BUFFER 10000

void strcat(char *s, char *t);

int main(int argc, char *argv[])
{
        char string1[STR_BUFFER] = "What A ";
        char string2[STR_BUFFER] = "Wonderful World!";

        printf ("String 1: %s\n", string1);

        strcat(string1, string2);

        printf ("String 2: %s\n", string2);
        printf ("Cat Result: %s\n", string1);

        return 0;
}

void strcat(char *s, char *t) {
    while (*s != '\0') {
        ++s;
    }
    
    // back s to '\0'
    s--;

    while (*s++ = *t++) {
        ;
    }
}