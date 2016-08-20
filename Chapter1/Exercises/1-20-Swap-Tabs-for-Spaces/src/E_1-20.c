#include <stdio.h>

#define TABSIZE 4
#define MAXLINE 1000

int getline( char s[], int max );
void replacetab( char s[], char temp[] );

main()
{
	int len;
	char line[MAXLINE];
	char temp[MAXLINE];
	while( (len = getline( line, MAXLINE ) ) > 0  )
	{
		replacetab( line, temp );
		printf( "%s", temp );
	}
}

int getline( char s[], int max )
{
	int c, i;
	c = i = 0;
	for( ; i < ( max - 1 ) && (c = getchar() ) != EOF && c != '\n'; i++ )
		s[i] = c;
	if( s[i] = '\n' )
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void replacetab( char s[], char temp[] )
{
	int readindex, writeindex;
	readindex = writeindex = 0;
	int counter;

	for ( ; readindex < MAXLINE - 1 && s[readindex] != '\0'; ++readindex )
	{
		if ( s[readindex] == '\t' )
			for ( counter = 0; counter < TABSIZE; counter++, writeindex++ )
				temp[writeindex] = ' ';
		else
			temp[writeindex++] = s[readindex];
	}
	temp[writeindex] = '\0';
}