#include <stdio.h>

int main(void){

    int current_char = 0;

    while((current_char = getchar()) != EOF){
        switch (current_char){
            case '\t': putchar('\\'); putchar('t');  break;
            case '\b': putchar('\\'); putchar('b');  break;
            case '\\': putchar('\\'); putchar('\\'); break;
            default: putchar(current_char);          break;
        }
    }
    return 0;
}