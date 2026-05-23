#include <stdio.h>

#define ARRAY_SIZE 128

int main(void){

    int char_array[ARRAY_SIZE] = {0};
    int current_char = 0;

    do{
        current_char = getchar();
        if(current_char != EOF){
            ++char_array[current_char];
        }
    } while(current_char != EOF);

    printf("ASCII Value\n");
    for(int row = 0; row < ARRAY_SIZE; ++row){
        if(char_array[row] != 0){
            printf("%03d :", row);
            for(int counter = char_array[row]; counter > 0; --counter){
                printf("*");
            }
            printf("Amount: %d\n", char_array[row]);
        }
    }
}