#include <stdio.h>

/* Print Celsius-Fahrenheit table
 * for cel = 0, 20, ..., 300;
 * floating-point version. */
int main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0; // Lower limit of celsius table.
	upper = 300;// Upper limit of celsius table.
	step = 20; // Step size.

	celsius = lower;
	
	printf( "Celsius\tFahrenheit\n" );

	while( celsius <= upper )
	{
		fahr = ( celsius * ( 9.0 / 5.0 ) ) + 32.0; 
		printf( "%3.0f\t%6.1f\n", celsius, fahr );
		celsius = celsius + step;
	}
	return 0;
}
