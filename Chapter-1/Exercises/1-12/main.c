#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main(void){

    int state = OUT_WORD;
    int current_character = 0;
    while((current_character = getchar()) != EOF){
        if(current_character != EOF){
            if(current_character == ' ' || current_character == '\n' || current_character == '\t'){
                if(state == IN_WORD){
                    printf("\n");
                }
                state = OUT_WORD;
            }
            else{
                state = IN_WORD;
                putchar(current_character);
            }
        }
    } 
    return 0;
}