#include <stdio.h>

/*
    Write the function any(s1, s2), which returns the first location
    in the string s1 where any character from the string s2 occurs,
    or -1 if s1 contains no characters from s2. (the standard library
    function strpbrk does the same job but returns a pointer to the
    location.)
*/
int any(char[], char[]);

int main(){
    char charstring[] = "alright then";
    char find[] = "tb";
    int index = 0;
    printf("String: %s\nTo be found: %s\n", charstring, find);
    index = any(charstring, find);
    printf("Result index: %d\n", index);
    return 0;
}

int any(char s1[], char s2[]){

    int s1read = 0, s2read = 0;

    for(; s1[s1read] != '\0'; s1read++){
        for(s2read = 0; s2[s2read] != '\0'; s2read++){
            if(s1[s1read] == s2[s2read]){
                return s1read;
            }
        }
    }
    return -1;
}