#include <stdio.h>

#define MAX_LINE 1000

int reverse(char[]);
int kr_getline(char[], int);

int main(void){

    int line_length = 0;
    char char_array[MAX_LINE];
    while((line_length = kr_getline(char_array, MAX_LINE)) > 0){
        reverse(char_array);
        printf("%s", char_array);
    }
    return 0;
}

int reverse(char char_array[]){

    int array_length = 0;
    char temp_holder = '\0';
    int index = 0;

    for(index = 0; char_array[index] != '\0'; ++index){
        ++array_length;
    }
    index = 0;
    --array_length; /* Backs up before the null terminator */

    /* If it ends in a newline, don't touch it */
    if (char_array[array_length] == '\n'){
        --array_length;
    }
    while(index < array_length){
        temp_holder = char_array[index];
        char_array[index] = char_array[array_length];
        char_array[array_length] = temp_holder;
        ++index;
        --array_length;
    }
    return 1;
}

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