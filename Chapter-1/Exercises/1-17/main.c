#include <stdio.h>

#define MAX_LINE 1000                      /* maximum input line size */
#define WRITE_LINE 80
int kr_getline(char[], int);

/* print longest input line */
int main(void){
    int line_length = 0;                   /* Current line length */
    char line[MAX_LINE] = {'\0'};          /* Current input line */

    while ((line_length = kr_getline(line, MAX_LINE)) > 0){
        if (line_length > WRITE_LINE){
            printf("%s", line);
        }
    }
    return 0;
}

/* getline: Read a line into s, return length */
int kr_getline(char character_array[], int limit){
    int character = 0, index1 = 0, index2 = 0;

    for(index1 = 0; (character = getchar()) != EOF && character != '\n'; ++index1){
        if(index1 < limit - 2){
            character_array[index2] = character;
            ++index2;
        }
    }
    if(character == '\n' && index2 < limit){
        character_array[index2] = character;
        ++index1;
        ++index2;

    }
    character_array[index2] = '\0';
    return index1;
}
