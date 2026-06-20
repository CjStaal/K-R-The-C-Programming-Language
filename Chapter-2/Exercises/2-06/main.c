#include <stdio.h>

/*
    Write a function setbits(x,p,n,y) that returns x with the n bits that
    begin at position p set to the rightmost n bits of y, leaving the
    other bits unchanged.
*/

unsigned setbits(unsigned, int, int, unsigned);

int main(){

    unsigned x = 0x61;
    unsigned y = 0x2F;
    int p = 5;
    int n = 2;
    printf("Before:\nx=%u\ny=%u\np=%d\nn=%d\n",x,y,p,n);
    x= setbits(x,p,n,y);
    printf("After:%u\n", x);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){

    unsigned mask = ~(~0u << n);
    int shift = p + 1 - n;
    return (x & ~(mask << shift)) | ((y & mask) << shift);
}