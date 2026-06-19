#include <stdio.h>
#include <limits.h>
/*
    Exercise 2-03
    Write the function htoi(s), which converts a string of hexadecimal digits
    (including an optional 0x or 0X) into its equivalent integer value.
    The allowable digits are 0 through 9, a through f, and A through F.
*/
    
int htoi(char[]);
int hexvalue(char);
int checkprefix(char*);

int main(){

    char hex[] = "0xAF81A1";
    int result = htoi(hex);
    if(result == -1){
        printf("Error\n");
        return -1;
    }
    printf("%s is %d\n", hex, result);

    return 0;
}


int htoi(char hexstring[]){
    
    int index = checkprefix(hexstring);

    if(index == -1){
        return -1;
    }

    if(hexstring[index] == '\0'){
        return -1;
    }

    int total = 0, digit = 0;
    for(; hexstring[index] != '\0'; index++){
        digit = hexvalue(hexstring[index]);
        if(digit == -1){
            return -1;
        }
        if (total > (INT_MAX - digit) / 16) {
            return -1;
        }
        total = (total << 4) + digit;
    }
    return total;
}

int checkprefix(char *hexstring){

    if(hexstring == NULL){
        return -1;
    }

    if (hexstring[0] == '\0'){
        return -1;
    }

    if(hexstring[0] == '0' ){
        if(hexstring[1] == 'x' || hexstring[1] == 'X'){
            return 2;
        }
    }
    return 0;
}

int hexvalue(char character){

        if((character >= '0' && character <= '9') ||
           (character >= 'A' && character <= 'F') ||
           (character >= 'a' && character <= 'f')){
            return (character & 0xF) + (character >> 6) * 9;
        }

        return -1;
}

