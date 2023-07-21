#include <stdio.h>

// copy input to output, replace tab by \t, backspace by \b
// backslash by \\

int main() {
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}