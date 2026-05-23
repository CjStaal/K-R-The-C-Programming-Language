#include <stdio.h>
/* print Celsius-Fahrenheit table
    for Cel = 0, 5, ..., 100; floating-point version*/
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;     /* Lower limit of temperature table */
    upper = 100;   /* Upper limit */
    step = 5;     /* step size */

    celsius = lower;

    printf("%s   %s\n", "Cel", "Fahr");
    while ( celsius <= upper){
        fahr = (celsius * (9.0/5.0)) + 32;
        printf( "%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}