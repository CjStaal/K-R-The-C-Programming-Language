#include <stdio.h>

#define MAX_LINE 1000

int kr_getline(char[], int);

int main(void){

    char line[MAX_LINE] = {'\0'};
    int line_length = 0;
    int index = 0;
    while((line_length = kr_getline(line, MAX_LINE)) > 0){
        if(line_length >= MAX_LINE){
            index = MAX_LINE -1;
        }
        else{
            index = line_length -1;
        }
        for(;(line[index] == ' ' || line[index] == '\t' || line[index] == '\0') && index > 0; --index){
            line[index] = '\0';
        }
        if(line[0] != '\0'){
            printf("%s", line);
        }
    }
    return 0;
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
