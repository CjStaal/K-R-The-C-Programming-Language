#include <stdio.h>
#include <limits.h>
/*Exercise 2-01:
    Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation. Harder if you
    compute them: determine the ranges of the various floating-point types.
*/


int main(void){

    printf("Getting sizes from limits.h definitions\n");

    printf("Max char value: %d\n", CHAR_MAX);
    printf("Min char value: %d\n", CHAR_MIN);

    printf("Maximum signed char value: %d\n", SCHAR_MAX);
    printf("Minumum signed char value: %d\n", SCHAR_MIN);
    printf("Maximum unsigned char value: %u\n", UCHAR_MAX);

    printf("Maximum short value: %d\n", SHRT_MAX);
    printf("Minimum short value: %d\n", SHRT_MIN);
    printf("Maximum unsigned short value: %u\n", USHRT_MAX);

    printf("Maximum int value: %d\n", INT_MAX);
    printf("Minumum int value: %d\n", INT_MIN);
    printf("Maximum unsigned int value: %u\n", UINT_MAX);

    printf("Maximum long value: %ld\n", LONG_MAX);
    printf("Minimum long value: %ld\n", LONG_MIN);
    printf("Maximum unsigned long value: %lu\n", ULONG_MAX);

    printf("Maximum long long value: %lld\n", LLONG_MAX);
    printf("Minimum long long value: %lld\n", LLONG_MIN);
    printf("Maximum unsigned long long value: %llu\n", ULLONG_MAX);


    printf("Getting sizes from computation methods\n");

    unsigned int uint_max = 0U - 1U;
    printf("Maximum unsigned int value: %u\n", uint_max);

    int int_max = uint_max / 2;
    printf("Maximum int value: %d\n", int_max);
    int int_min = -int_max - 1;
    printf("Minimum int value: %d\n", int_min);

    unsigned char uchar_max = (unsigned char) (0U - 1U);
    printf("Maximum unsigned char value: %u\n", (unsigned int) uchar_max);
    signed char schar_max = uchar_max / 2;
    printf("Maximum signed char value: %d\n", schar_max);
    signed char schar_min = -schar_max - 1;
    printf("Miiumum signed char value: %d\n", schar_min);

    unsigned short ushrt_max = (unsigned short) (0U - 1U);
    printf("Maximum unsigned short value: %u\n", (unsigned int) ushrt_max);
    short shrt_max = ushrt_max / 2;
    printf("Maximum short value: %d\n", shrt_max);
    short shrt_min = -shrt_max - 1;
    printf("Minimum short value: %d\n", shrt_min);

    unsigned long ulong_max = 0UL - 1UL;
    printf("Maximum unsigned long value: %lu\n", ulong_max);
    long long_max = ulong_max / 2;
    printf("Maximum long value: %ld\n", long_max);
    long long_min = -long_max - 1;
    printf("Minimum long value: %ld\n", long_min);

    unsigned long long ullong_max = 0ULL - 1ULL;
    printf("Maximum unsigned long long value: %llu\n", ullong_max);
    long long llong_max = ullong_max / 2;
    printf("Maximum long long value: %lld\n", llong_max);
    long long llong_min = -llong_max - 1;
    printf("Minimum long long value: %lld\n", llong_min);

    return 0;
}