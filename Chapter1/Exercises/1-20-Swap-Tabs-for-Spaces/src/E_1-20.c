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

int getline(char s[], int max )
{
	int c;
	int i = 0;
	for( i = 0; i < ( max - 1 ) && (c = getchar() ) != EOF && c != '\n'; i++ )
		s[i] = c;
	if( s[i] = '\n' )
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void replacetab(char s[], char temp[])
{
	int i1 = 0;
	int i;
	int counter;
	for (i = 0; i < MAXLINE - 1 && s[i] != '\n' && s[i] != '\0'; ++i)
	{
		if (s[i] == '\t')
			for (counter = 0; counter < TABSIZE; counter++)
				temp[i1++] = ' ';
		else
			temp[i1++] = s[i];
	}
	temp[i1] = '\0';
}

