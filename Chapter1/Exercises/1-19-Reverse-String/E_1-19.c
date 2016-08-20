#include <stdio.h>

int get_array_size(char s[]);
void reverse_string(char s[]);
main()
{
	char string[] = "StringDingaling";
	printf("String: %s\n", string);
	reverse_string(string);
	printf("Reversed string: %s\n", string);
	return 0;
}

void reverse_string(char s[])
{
	char temp;
	int index0, index1;
	index0 = 0;
	index1 = get_array_size(s) - 1;
	printf( "Array size: %d\n", index1 );
	for(; index0 < index1; index0++, index1--)
	{
		temp = s[index0];
		s[index0] = s[index1];
		s[index1] = temp;	
	}
}

int get_array_size(char s[])
{
	int c = 0;
	while( s[c] != '\0' )
		++c;
	return c;
}
