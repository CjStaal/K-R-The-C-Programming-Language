#include <stdio.h>

main()
{
	int c, tabs, blanks, newlines;
	tabs = blanks = newlines = 0;
	while( (c = getchar() ) != EOF)
	{
		if(c == '\t')
			++tabs;
		else if(c == ' ')
			++blanks;
		else if(c == '\n')
			+newlines;
	}
	printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}