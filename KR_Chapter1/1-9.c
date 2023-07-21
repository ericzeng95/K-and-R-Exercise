#include <stdio.h>

// program to copy input to output, replacing string of more than one
// blanks to one blank

int main(){
    char prev = '1';
    char c;

    while ((c=getchar())!=EOF)
    {
        if (prev != ' '){
            putchar(c);
        }
        prev = c;
    }
        
}