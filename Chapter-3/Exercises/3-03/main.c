#include <stdio.h>

/*
    Write a function expand(s1,s2) that expands shorthand
    notations like a-z in the string s1 into the equivalent
    complete list abc...xyz in s2. Allow for letters of either
    case and digits, and be prepared to handle cases like a-b-c
    and a-z0-9 and -a-z. Arrange that a leading or trailing - is
    taken literally.
*/
#define MAXLINE 1000

void expand(const char[], char[]);

int main(){

    char *testcase[] = {
        "a-z",
        "a-z0-9",
        "a-b-c",
        "-a-z",
        "a-z",
        "-a-z-",
        "a-Z",
        "A-Z"
    };
    char output[MAXLINE];

    int index = 0, count = sizeof(testcase)/sizeof(testcase[0]);
    for(index = 0; index < count; index++){
        expand(testcase[index], output);
        printf("%s -> %s\n", testcase[index], output);
    }

    return 0;
}

void expand(const char inputline[], char outputline[]){
    int read = 0, write = 0;
    while (inputline[read] != '\0'){
        if((read > 0 && inputline[read+1] != '\0') && inputline[read] == '-'){

        }
        else{
            outputline[write++] = inputline[read++];
        }
    }

    outputline[write] = '\0';

}