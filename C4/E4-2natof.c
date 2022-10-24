/* E4-2 extended atof to handle scientific notation of 123.45e-6 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double natof(char s[]) {
    double val, power;
    int i, sign, exp, exp_sign;
    exp = 0;
    exp_sign = 1;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++; 
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // Added section for scientific notation
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (!isdigit(s[i]))
            exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++; 
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    return sign * val / power * pow(10, exp_sign * exp);
}

int main() {
    double f;
    f = natof("123.45e-6");
    printf("%f\n", f);
    return 0;
}