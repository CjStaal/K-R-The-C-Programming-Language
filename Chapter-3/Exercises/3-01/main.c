#include <stdio.h>
#include <limits.h>

/*
    Our binary search makes two tests inside the loop, when one
    would suffice (at the cprice of more tests outside). Write a
    version with only one test inside the loop and measure the
    difference in run-time.
*/

int binsearch(int, int[], int);
int binsearch2(int, int[], int);

int main(){

    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    binsearch(7, array, (sizeof(array) / sizeof(int)));
    binsearch2(7, array, (sizeof(array) / sizeof(int)));

}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high) / 2;
        if( x < v[mid]){
            high = mid - 1;
        }
        else if (x > v[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }

    if (n > 0 && v[low] == x)
        return low;
    else
        return -1;
}