#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in it's input.
    It must be vertical.*/
#define MAX_WORD_LENGTH 15


int main(void){

    int current_character = 0;
    int word_lengths[MAX_WORD_LENGTH] = {0};
    int word_length = 0, max_length_found = 0;
    int index = 0;
    int row = 0;
    int max_count = 0;


    do{
        current_character = getchar();
        if(current_character == ' ' || current_character == '\t' ||
            current_character == '\n' || current_character == EOF){
            if(word_length > 0 && word_length < MAX_WORD_LENGTH){
                if (word_length > max_length_found){
                    max_length_found = word_length;
                }
                ++word_lengths[word_length];
                word_length = 0;
            }
            else if (word_length > 0 && word_length > MAX_WORD_LENGTH){
                printf("Word length is larger than buffer.\n");
                break;
            }
        }
        else{
            ++word_length;
        }
    } while (current_character != EOF);


    for(index = 1; index <= max_length_found; ++index){
        if(word_lengths[index] > max_count){
            max_count = word_lengths[index];
        }
    }

    for(row = max_count; row > 0; --row){
        for(index = 1; index <= max_length_found; ++index){
            if(word_lengths[index] >= row){
                printf(" * ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }

    for (index = 1; index <= max_length_found; ++index){
        printf(" %3d ", index);
    }
    printf("\n");
}