#include <stdio.h>

/*
    Write an alternate version of squeeze(s1, s2) that deletes each
    character in s1 that matches any character in the string s2.
*/
void squeeze(char[], char[]);

int main(){
    char charstring[] = "alright then";
    char removestring[] = "ab";
    printf("String before: %s\nTo be removed: %s\n", charstring, removestring);
    squeeze(charstring, removestring);
    printf("Result: %s\n", charstring);
    return 0;
}

void squeeze(char s1[], char s2[]){

    int s1read = 0, s1write = 0, s2read = 0, found = 0;

    for(; s1[s1read] != '\0'; s1read++){
        for(s2read = 0; s2[s2read] != '\0'; s2read++){
            if(s1[s1read] == s2[s2read]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            s1[s1write++] = s1[s1read];
        }
        found = 0;
    }
    s1[s1write] = '\0';
}