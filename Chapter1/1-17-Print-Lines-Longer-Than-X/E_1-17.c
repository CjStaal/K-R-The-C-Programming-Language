#include <stdio.h>

#define size_to_print 80
#define MAXLINE 1000 
int getline( char line[], int maxline );

main()
{
	int len; /* Current line length */
	char line[MAXLINE]; /* Current line */

	while( (len = getline( line, MAXLINE ) ) > 0 ) /* Stops at EOF */
		if ( len > size_to_print )
			printf( "%s", line );
}
 

/* getline: reads a line in to s, returns length */
int getline( char s[], int lim )
{
	int c, i; //character and index.

	for( i = 0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
		s[i] = c;
	if ( c ==  '\n' )
		s[i] = c;
	s[++i] = '\0';
	return i;
}
