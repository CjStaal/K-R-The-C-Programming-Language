#include <stdio.h>

/*
    Write a function escape(s,t) that converts characters like newline and
    tab into visible escape sequences like \n and \t as it copies the string
    t to s. Use a switch. Write a function for the other direction as well,
    converting escape sequences into the real characters.
*/

void escape(char[], char[]);
void unescape(char[], char[]);

int main(){
    char original[] = "hello\tworld\nnext line";
    char escaped[100];
    char unescaped[100];

    escape(escaped, original);
    printf("Escaped:\n%s\n", escaped);

    unescape(unescaped, escaped);
    printf("Unescaped:\n%s\n", unescaped);

    return 0;
}

void escape(char s[], char t[]){
    
    int read = 0, write = 0;
    for(read = 0, write = 0; t[read] != '\0'; read++){
        switch(t[read]){
            case '\n':
                s[write++] = '\\';
                s[write++] = 'n';
                break;
            case '\t':
                s[write++] = '\\';
                s[write++] = 't';
                break;
            default:
                s[write++] = t[read];
                break;
        }
    }
    s[write]= '\0';
}

void unescape(char s[], char t[]){

    int read = 0, write = 0;
    for(read = 0, write = 0; t[read] != '\0'; read++){
        switch(t[read]){
            case '\\':
                switch(t[read+1]){
                    case 'n':
                        s[write++] = '\n';
                        read++;
                        break;
                    case 't':
                        s[write++] = '\t';
                        read++;
                        break;
                    default:
                        s[write++] = t[read];
                        break;
                }
                break;
            default:
                s[write++] = t[read];
                break;
        }
    }
    s[write]= '\0';
}