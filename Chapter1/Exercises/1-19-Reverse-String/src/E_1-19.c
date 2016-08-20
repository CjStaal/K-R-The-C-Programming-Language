#include <stdio.h>

#define MAXLINE 1000

int getline(char line[]);
int get_strlen(char s[]);
void reverse_string(char s[]);

main()
{
	int len;
	char line[MAXLINE];

	while( (len = getline( line ) ) > 0 )
	{
		reverse_string( line );
		printf( "Reversed string: %s\n", line );
	}

	return 0;
}

void reverse_string( char s[] )
{
	char temp;
	int index0, index1;
	index0 = 0;
	index1 = get_strlen( s ) - 1;
	for( ; index0 < index1; index0++, index1-- )
	{
		temp = s[index0];
		s[index0] = s[index1];
		s[index1] = temp;	
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

int get_strlen( char s[] )
{
	int i = 0;
	while( s[i] != '\0' )
		i++;
	return i;
}