#include <stdio.h>

#define MAX_LINE 1000
#define TAB_LENGTH 4

int kr_getline(char[], int);

int entab(char[]);

int main(void){
    char line[MAX_LINE];

    while(kr_getline(line, MAX_LINE) > 0){
        entab(line);
        printf("%s", line);
    }
    return 0;
}

int kr_getline(char char_array[], int max_length){
    int character = 0, index = 0;

    for(; index < (max_length - 1) && (character = getchar()) != EOF && character != '\n'; ++index){
        char_array[index] = character;
    }
    if( character == '\n'){
        char_array[index++] = character;
    }
    char_array[index] = '\0';
    return index;
}

int entab(char char_array[]){
    int read_index = 0, write_index = 0, column = 0;

    while(char_array[read_index] != '\0'){
        if(char_array[read_index] == ' '){
            int space_start = read_index;
            int temp_col = column;
            while(char_array[read_index] == ' '){
                ++read_index;
                ++temp_col;
                if(temp_col % TAB_LENGTH == 0){
                    char_array[write_index++] = '\t';
                    space_start = read_index;
                    column = temp_col;
                }
            }
            /* leftover spaces that didn't reach a tab stop */
            while(space_start < read_index){
                char_array[write_index++] = ' ';
                ++space_start;
                ++column;
            }
        }
        else{
            char_array[write_index++] = char_array[read_index++];
            ++column;
        }
    }
    char_array[write_index] = '\0';
    return write_index;
}