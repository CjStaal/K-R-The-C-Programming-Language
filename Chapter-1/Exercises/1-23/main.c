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

int process_char(int, int);

int main(void){
    int current_char = '\0';
    int state = NORMAL;
    while((current_char = getchar()) != EOF){
        state = process_char(current_char, state);
    }
    if(state == SAW_SLASH){
        putchar('/');
    }
    return 0;
}

int process_char(int current_char, int state){
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
    }
    return state;
}