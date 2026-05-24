#include <stdio.h>

#define TAB_SIZE 4
#define MAX_LINE 1000

int kr_getline(char[], int);
void replace_tab(char[], char[]);

int main(void){

    int length = 0;
    char line[MAX_LINE];
    char temp_line[MAX_LINE];

    while( (length = kr_getline(line, MAX_LINE)) > 0){
        replace_tab(line, temp_line);
        printf("%s", temp_line);
    }
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

void replace_tab(char char_array[], char temp_char_array[]){
    int read_index = 0, write_index = 0, counter = 0, required_spaces = 0;

    for(; read_index < ( MAX_LINE - 1 ) && (char_array[read_index] != '\0'); ++read_index){
        if(char_array[read_index] == '\t'){
            required_spaces = TAB_SIZE - (write_index % TAB_SIZE);
            for (counter = 0; counter < required_spaces; ++counter, ++write_index){
                temp_char_array[write_index] = ' ';
            }
        }
        else{
            temp_char_array[write_index++] = char_array[read_index];
        }
    }
    temp_char_array[write_index] = '\0';
}