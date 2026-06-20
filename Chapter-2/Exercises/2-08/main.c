#include <stdio.h>
#include <limits.h>

/*
    Write a function rightrot(x,n) that returns the value of the
    integer x rotated to the right by n bit positions.
*/

unsigned rightrot(unsigned, int);

int main(){
    unsigned x = 0x7D;
    int n = 2;
    printf("Before:\nx=%u\n=%d\n",x,n);
    x = rightrot(x,n);
    printf("After:%u\n", x);
    return 0;
}

unsigned rightrot(unsigned x, int n){
    int width = sizeof(unsigned) * CHAR_BIT;
    n = n % width;

    if(n == 0){
        return x;
    }
    
    return (x >> n) | (x << (width - n));
}