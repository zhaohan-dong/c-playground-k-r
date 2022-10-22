/* exercise 3-2 escape(s,t) that converts characters into visible escape sequences 
    use switch*/

#include<stdio.h>
#include<string.h>

int escape(char * s, char * t);

int main(void) {
    char str1[256] = "Oops! ";
    char str2[256] = "P\ri\n\ti\ng out escape sequences.";

    printf("%s\n", str1);
    printf("%s\n", str2);
    escape(str1, str2);
    printf("string: %s\n", str1);
}

int escape(char * s, char * t)
{
    int i;
    int j = strlen(s);
    for (i = 0; t[i] != '\0'; ++i) {
        switch (t[i])
        { // add escape and advance index
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\r':
            s[j++] = '\\'; 
            s[j++] = 'r';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
    return 0;
}
