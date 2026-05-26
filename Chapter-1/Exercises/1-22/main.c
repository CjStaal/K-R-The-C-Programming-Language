#include <stdio.h>

#define LINE_LENGTH 80
#define MAX_LENGTH 1000

int kr_getline(char[], int);
void word_wrap(char[], int);
void print_word(char[], int, int);

int main(void){
    char char_array[MAX_LENGTH] = {'\0'};
    while(kr_getline(char_array, MAX_LENGTH) > 0){
        word_wrap(char_array, LINE_LENGTH);
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

void word_wrap(char char_array[], int max_line_length){
    int column = 0, index = 0, word_length = 0, remaining = 0;

    while(char_array[index] != '\0'){
        while(char_array[index] == ' ' || char_array[index] == '\t'){
            index++;
        }
        word_length = 0;
        while(char_array[index] != ' ' && char_array[index] != '\t' &&
                char_array[index] != '\n' && char_array[index] != '\0'){
            word_length++;
            index++;
        }
        if(word_length == 0){
            if(char_array[index] == '\n'){
                column = 0;
                index++;
            }
            continue;
        }
        if(word_length > max_line_length){
            if(column > 0){
                putchar('\n');
            }
            remaining = word_length;
            while(remaining > max_line_length){
                print_word(char_array, index - remaining, max_line_length);
                putchar('\n');
                remaining -=max_line_length;
            }
            print_word(char_array, index - remaining, remaining);
            column = remaining;
        }
        else if(column == 0){
            print_word(char_array, index - word_length, word_length);
            column = word_length;
        }
        else if(column + 1 + word_length <= max_line_length){
            putchar(' ');
            print_word(char_array, index - word_length, word_length);
            column += 1 + word_length;

        }
        else{
            putchar('\n');
            print_word(char_array, index - word_length, word_length);
            column = word_length;
        }
    }
    putchar('\n');
}

void print_word(char char_array[], int start, int length){
    while(length > 0){
        putchar(char_array[start++]);
        length--;
    }
}