#include <stdio.h>

#define MAXLINE 1000

void remove_trailing ( char s[] );
int getline ( char line[] );

main()
{
	int len;
	char line[MAXLINE]; 
	while( (len = getline(line) ) > 0 )
	{
		remove_trailing( line );
		printf( "%s", line );
	}
}

/* getline: reads line into .... line and returns line length*/
int getline( char line[] )
{
	int c, i;
	int lim = MAXLINE;
	for( i=0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n'; ++i)
		line[i] = c;
	if ( c = '\n' )
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* remove_trailing: removes trailing white space from lines */
void remove_trailing ( char s[] )
{
	int index_of_last_char, index, len;

	index_of_last_char = index = 0;
	len = sizeof s;

	for(index = 0; index < len; ++index )
		if( s[index] != '\t' && s[index] != ' ' && index != '\n')
			index_of_last_char = index;

	index = index_of_last_char;
	s[++index] = '\n';
	s[++index] = '\0';

	/* Can't be lettin niggas see what use to be there. Gotta keep that shit on the hush */
	for( ; index < len; ++index )
		s[index] = '\0';
}	 

