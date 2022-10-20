#include<stdio.h>
/* page 8 print Fahrenheit-Celsius table
    for f = 0, 20, ..., 300 */
#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float fahr, celsius;
    
    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%4.0f %6.2f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}