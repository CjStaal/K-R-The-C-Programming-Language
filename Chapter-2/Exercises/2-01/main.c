#include <stdio.h>
#include <limits.h>
/*Execise 2-01:
    Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation. Harder if you
    compute them: determine the ranges of the various floating-point types.
*/


int main(void){
    printf("char number of bits: %d\n", CHAR_BIT);
    printf("Max char value: %d\n", CHAR_MAX);
    printf("Min char value: %d\n", CHAR_MIN);
    printf("Maximum signed char value: %d\n", SCHAR_MAX);
    printf("Minumum signed char value: %d\n", SCHAR_MIN);
    printf("Maximum unsigned char value: %d\n", UCHAR_MAX);
    printf("Maximum short value: %d\n", SHRT_MAX);
    printf("Minimum short value: %d\n", SHRT_MIN);
    printf("Maximum unsigned short value: %d\n", USHRT_MAX);
    printf("Maximum int value: %d\n", INT_MAX);
    printf("Minumum int value: %d\n", INT_MIN);
    printf("Maximum unsigned int value: %d\n", UINT_MAX);
    printf("Maximum long value: %d\n", LONG_MAX);
    printf("Minimum long value: %d\n", LONG_MIN);
    printf("Maximum unsigned long value: %d\n", ULONG_MAX);
    printf("Maximum long long value: %d\n", LLONG_MAX);
    printf("Minimum long long value: %d\n", LLONG_MIN);
    printf("Maximum unsigned long long value: %d\n", ULLONG_MAX);
    return 0;
}