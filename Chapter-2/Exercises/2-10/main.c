#include <stdio.h>

/*
    Rewrite the function lower, which converts upper case letters
    to lower case, with a condition expression instead of if-else.
*/
char lower(char);

int main(){

    char x = 'A';
    x = lower(x);
    return 0;
}
char lower(char character){
    return (character >= 'A' && character <= 'Z')
        ?  (character | 0x20)
        : character;
}