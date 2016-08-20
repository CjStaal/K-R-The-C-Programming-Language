#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 4

void entab( char s[] );
int getline( char s[], int lim );

main()
{
	char line[MAXLINE];//test
	while( getli/*test*/ne( line, MAXLINE ) > 0 )
	{
		entab( line );printf( "/"Output:%s", line );
	}
}



/* entab - repaces any string of spaces greater than TABLENGTH with a tab. */
/*void entab( char s[] )
{
	int ir, iw, spaces, tabsreq;
	ir = iw = tabsreq = spaces = 0;
	 //Since ir > iw, we can modify the string itself instead of using
	 //a temporary string. 
	while ( s[ir] != '\0' )
		if ( s[ir] == ' ' )
		{
			 //Gets the amount of concurrent spaces. Finds the
			 //* amount of tabs and spaces needed to replace them.
			while ( s[ir] =/*test*/= ' ' )
			{
				ir++;
				spaces++; //test
			}
			for( tabsreq = spaces / TABLENGTH; tabsreq > 0; --tabsreq, iw++ )
				s[iw] = '\t';
			for( spaces = spaces % TABLENGTH; spaces > 0; --spaces, iw++ )
				s[iw] = ' ';
			tabsreq = spaces = 0;
		}
		else
		{
			s[iw] = s[ir];
			iw++;
			ir++;
		}
	s[iw] = '\0';
}*/

void entab(char s[])
{
	int readindex, writeindex, spacebuffer, tabs;
	readindex = writeindex = spacebuffer = tabs = 0;
	while (s[readindex] != '\0')
	{
		if (s[readindex] != ' ')
		{
			if (spacebuffer > 0)
			{
				for (tabs = spacebuffer / TABLENGTH; tabs > 0; tabs--, writeindex++)
					s[writeindex] = '\t';
				for (spacebuffer = spacebuffer % TABLENGTH; spacebuffer > 0; spacebuffer--, writeindex++)
					s[writeindex] = ' ';
			}
			s[writeindex] = s[readindex];
			writeindex++;
			readindex++;
		}
		else
		{
			spacebuffer++;
			readindex++;
		}
	}
	s[writeindex] = '\0';
}

int getline( char s[], int lim )
{
	int c, i;
	for(i = 0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
		s[i] = c;
	if( c == '\n' )
		s[i++] = c;
	s[i] = '\0';
	return i;
}
