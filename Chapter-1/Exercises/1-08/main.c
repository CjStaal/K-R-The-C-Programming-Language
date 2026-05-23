#include <stdio.h>

int main(void){
    
    int current_char = 0;
    int tabs = 0, newlines = 0, blanks = 0;
    while((current_char = getchar()) != EOF){
        switch (current_char){
            case '\t': ++tabs;  break;
            case '\n': ++newlines;  break;
            case ' ': ++blanks; break;
            default: break;
        }
    }
    printf("%d tabs\n%d new lines\n%d blanks\n", tabs, newlines, blanks);
    return 0;
}