#include <stdio.h>

#define MAX_LINE 1000                      /* maximum input line size */

int kr_getline(char[], int);
void copy(char[], char[]);

/* print longest input line */
int main(void){
    int line_length = 0;                   /* Current line length */
    int max_line_length = 0;               /* Maximum length seen so far */
    char line[MAX_LINE] = {'\0'};          /* Current input line */
    char longest_line[MAX_LINE] = {'\0'};  /* Longest line saved here */

    while ((line_length = kr_getline(line, MAX_LINE)) > 0){
        if (line_length > max_line_length){
            max_line_length = line_length;
            copy(longest_line, line);
        }
    }
    if (max_line_length > 0){              /* There was a line */
        printf("%d, %s", max_line_length, longest_line);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char destination[], char source[]){
    int index = 0;

    while((destination[index] = source[index]) != '\0'){
        ++index;
    }
}