#include <stdio.h>

main()
{
	int c, spaces = 0;
	while( ( c = getchar() ) != EOF )
	{
		if( c == ' ' )
			++spaces;
		else 
			spaces = 0;
		if( spaces <= 1 )
			printf( "%c", c );
	}
}