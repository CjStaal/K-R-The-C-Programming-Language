#include <stdio.h>

#define MAX_DEPTH 1000

#define NORMAL 0
#define SAW_SLASH 1
#define COMMENT_SAW_STAR 2
#define IN_COMMENT 3
#define IN_LINE_COMMENT 4
#define IN_STRING 5
#define IN_CHAR 6
#define STRING_ESCAPE 7
#define CHAR_ESCAPE 8

int main(void){
    
    char bracket_stack[MAX_DEPTH] = {'\0'};
    int line_stack[MAX_DEPTH] = {'\0'};
    int column_stack[MAX_DEPTH] = {'\0'};
    int top = 0, column = 1, line = 1, state = NORMAL, current_char = '\0';

    while((current_char = getchar()) != EOF){
        switch(state){
            case NORMAL:
                if(current_char == '/'){
                    state = SAW_SLASH;
                }
                else if(current_char == '\"'){
                    state = IN_STRING;
                }
                else if(current_char == '\''){
                    state = IN_CHAR;
                }
                else if(current_char == '{' || current_char == '[' || current_char == '('){
                    bracket_stack[top] = current_char; 
                    line_stack[top] = line;
                    column_stack[top] = column;
                    state = NORMAL;
                    top++;
                }
                else if(current_char == ')'){
                    if(top > 0){
                        if(bracket_stack[top - 1] == '('){
                            --top;
                        }
                        else{
                            printf("Error line %d column %d, found ')' but last open was %c.\n", line, column, bracket_stack[top - 1]);
                        }
                    }
                    else if(top == 0){
                        printf("Attempted ')' with no opening.\n");
                    }
                    state = NORMAL;
                }
                else if(current_char == ']'){
                    if(top > 0){
                        if(bracket_stack[top - 1] == '['){
                            --top;
                        }
                        else{
                            printf("Error line %d column %d, found ']' but last open was %c.\n", line, column, bracket_stack[top - 1]);
                        }
                    }
                    else if(top == 0){
                        printf("Attempted ']' with no opening.\n");
                    }
                    state = NORMAL;
                }
                else if(current_char == '}'){
                    if(top > 0){
                        if(bracket_stack[top - 1] == '{'){
                            --top;
                        }
                        else{
                            printf("Error line %d column %d, found '}' but last open was %c.\n", line, column, bracket_stack[top - 1]);
                        }
                    }
                    else if(top == 0){
                        printf("Attempted '}' with no opening.\n");
                    }
                    state = NORMAL;
                }
                else{
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
                    state = IN_STRING;
                }
                else if(current_char == '\''){
                    state = IN_CHAR;
                }
                else{
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
                    state = NORMAL;
                }
                else if(current_char == '\\'){
                    state = STRING_ESCAPE;
                }
                else{
                    state = IN_STRING;
                }
            break;
            case STRING_ESCAPE:
                state = IN_STRING;
            break;
            case IN_CHAR:
                if(current_char == '\''){
                    state = NORMAL;
                }
                else if(current_char == '\\'){
                    state = CHAR_ESCAPE;
                }
                else{
                    state = IN_CHAR;
                }
            break;
            case CHAR_ESCAPE:
                state = IN_CHAR;
            break;
            case IN_LINE_COMMENT:
                if(current_char == '\n'){
                    state = NORMAL;
                }
                else{
                    state = IN_LINE_COMMENT;
                }
            break;
        }
        if(current_char == '\n'){
            column = 1;
            line++;
        }
        else{
            column++;
        }
    }
    while(top > 0){
        --top;
        printf("Unclosed '%c' at line %d column %d.\n", bracket_stack[top], line_stack[top], column_stack[top]);
    }
    if(state == IN_STRING || state == STRING_ESCAPE){
        printf("Unterminated string.\n");
    }
    else if(state == IN_CHAR || state == CHAR_ESCAPE){
        printf("Unterminated character constant.\n");
    }
    else if(state == IN_COMMENT || state == COMMENT_SAW_STAR){
        printf("Unterminated comment.\n");
    }
    return 0;
}
