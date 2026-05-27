#include <stdio.h>

#define MAX_LINE 1000

#define NORMAL 0
#define SAW_SLASH 1
#define COMMENT_SAW_STAR 2
#define IN_COMMENT 3
#define IN_LINE_COMMENT 4
#define IN_STRING 5
#define IN_CHAR 6
#define STRING_ESCAPE 7
#define CHAR_ESCAPE 8

int kr_getline(char[], int);
void remove_comments(char[], int);

int main(void){
    char char_array[MAX_LINE] = {'\0'};
    while(kr_getline(char_array, MAX_LINE) > 0){
        remove_comments(char_array, MAX_LINE);
    }
    return 0;
}
int kr_getline(char char_array[], int max_length){
    int character = 0, index = 0;

    for(; index < (max_length - 1) && (character = getchar()) != EOF && character != '\n'; ++index){
        char_array[index] = character;
    }
    if( character == '\n'){
        char_array[index++] = character;
    }
    char_array[index] = '\0';
    return index;
}
void remove_comments(char char_array[], int max_string_length){
    static int state = NORMAL;
    char current_char = '\0';
    for(int index = 0; index < max_string_length && char_array[index] != '\0'; ++index ){
        current_char = char_array[index];
        switch(state){
            case NORMAL:
                if(current_char == '/'){
                    state = SAW_SLASH;
                }
                else if(current_char == '\"'){
                    putchar(current_char);
                    state = IN_STRING;
                }
                else if(current_char == '\''){
                    putchar(current_char);
                    state = IN_CHAR;
                }
                else{
                    putchar(current_char);
                    state = NORMAL;
                }
            break;
            case SAW_SLASH:
                if(current_char == '*'){
                    state = IN_COMMENT;
                }
                else if(current_char == '/'){
                    state = IN_LINE_COMMENT;
                }
                else if(current_char == '\"'){
                    putchar('/');
                    putchar(current_char);
                    state = IN_STRING;
                }
                else if(current_char == '\''){
                    putchar('/');
                    putchar(current_char);
                    state = IN_CHAR;
                }
                else{
                    putchar('/');
                    putchar(current_char);
                    state = NORMAL;
                }
            break;
            case IN_COMMENT:
                if(current_char == '*'){
                    state = COMMENT_SAW_STAR;
                }
                else{
                    state = IN_COMMENT;
                }
            break;
            case COMMENT_SAW_STAR:
                if(current_char == '/'){
                    state = NORMAL;
                }
                else if(current_char == '*'){
                    state = COMMENT_SAW_STAR;
                }
                else{
                    state = IN_COMMENT;
                }
            break;
            case IN_STRING:
                if(current_char == '\"'){
                    putchar(current_char);
                    state = NORMAL;
                }
                else if(current_char == '\\'){
                    putchar(current_char);
                    state = STRING_ESCAPE;
                }
                else{
                    putchar(current_char);
                    state = IN_STRING;
                }
            break;
            case STRING_ESCAPE:
                putchar(current_char);
                state = IN_STRING;
            break;
            case IN_CHAR:
                if(current_char == '\''){
                    putchar(current_char);
                    state = NORMAL;
                }
                else if(current_char == '\\'){
                    putchar(current_char);
                    state = CHAR_ESCAPE;
                }
                else{
                    putchar(current_char);
                    state = IN_CHAR;
                }
            break;
            case CHAR_ESCAPE:
                putchar(current_char);
                state = IN_CHAR;
            break;
            case IN_LINE_COMMENT:
                if(current_char == '\n'){
                    putchar('\n');
                    state = NORMAL;
                }
                else{
                    state = IN_LINE_COMMENT;
                }
            break;
            default:
            break;
        }
    }
}