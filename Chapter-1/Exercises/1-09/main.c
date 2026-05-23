#include <stdio.h>

int main(void)
{

    int current_char = 0;
    int previous_char = 0;
    while ((current_char = getchar ()) != EOF)
    {
        if( (previous_char != ' ' ) || (current_char != ' ' ))
        {
            putchar(current_char);
        }
        previous_char = current_char;
    }

    return 0;
}