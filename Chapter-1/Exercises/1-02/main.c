#include <stdio.h>

int print_escape(char, char);
int main(void){

    print_escape('a', '\a');  //alert character
    print_escape('b', '\b');  //backspace
    print_escape('e', '\e');  //gcc extension
    print_escape('f', '\f');  //formfeed
    print_escape('m', '\m');  //undefined
    print_escape('n', '\n');  //newline
    print_escape('r', '\r');  //carriage return
    print_escape('t', '\t');  //tab
    print_escape('v', '\v');  //vertical tab
    print_escape('z', '\z');  //undefined
}

int print_escape(char value, char escape_value){
    return printf("%c, %c\n", value, escape_value);
}
