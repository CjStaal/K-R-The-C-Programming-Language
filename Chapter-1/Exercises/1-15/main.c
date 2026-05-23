#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = lower, and increments with
    step until upper is reached.*/

int fahr_to_cel(int);

int main(void){
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;     /* lower limit of temperature table */
    upper = 300;   /* upper limit */
    step = 20;     /* step size */

    fahr = lower;
    while (fahr <= upper){
        printf("%d\t%d\n", fahr, fahr_to_cel(fahr));
        fahr += step;
    }
    return 0;
}

/* Converts fahr to celsius */
int fahr_to_cel(int fahr){
    return 5 * (fahr-32) / 9;
}