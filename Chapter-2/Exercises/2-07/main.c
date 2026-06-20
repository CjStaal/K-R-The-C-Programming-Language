#include <stdio.h>

/*
    Write a function invert(x,p,n) that returns x with the n bits
    that begin at position p inverted (i.e., 1 changed in to 0 and
    vice versa), leaving the others unchanged.
*/

unsigned invert(unsigned, int, int);
int main(){
    unsigned x = 0x61;
    int p = 5;
    int n = 2;
    printf("Before:\nx=%u\np=%d\nn=%d\n",x,p,n);
    x = invert(x,p,n);
    printf("After:%u\n", x);
    return 0;
}

unsigned invert(unsigned x, int p, int n){
    unsigned mask = ~(~0u << n) << (p + 1 - n);
    return x ^ mask;
}