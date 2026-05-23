#include <stdio.h>

int reverse(char[]);
int kr_getline(char[], int);

int main(void){

}

int reverse(char char_array[]){

    int array_length = 0;
    char temp_holder = '\0';
    int index = 0;

    for(index = 0; char_array[index] != '\0'; ++index){
        ++array_length;
    }
    index = 0;

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