#include <stdio.h>

/*
    Exercise 2-02
    Write a loop equivilant to the for loop above without using && or ||.
*/

int main(void){
    int i = 0;
    int lim = 10;
    int c = 0;
    char s[100] = {0};

    for(i=0; i<lim-1; ++i){
        c = getchar();
        if(c == '\n'){
            break;
        }
        if(c == EOF){
            break;
        }
        s[i] = c;
    }
}