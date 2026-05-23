#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version*/
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     /* Lower limit of temperature table */
    upper = 300;   /* Upper limit */
    step = 20;     /* step size */

    fahr = lower;

    printf("%s   %s\n", "Fahr", "Cel");
    while ( fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf( "%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}