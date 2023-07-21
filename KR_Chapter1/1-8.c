#include <stdio.h>

// write a program to count blanks, tabs and newlines

int main(){
    int blank, tab, newline;
    blank = 0;
    tab = 0;
    newline = 0;
    int c;
    while ((c=getchar()) != EOF)
    {
        if (c == ' ') ++blank;
        if (c == '\t') ++tab;
        if (c == '\n') ++newline;

    }
    printf("Blanks: %d, Tabs: %d, Newlines: %d \b", blank, tab, newline);
}