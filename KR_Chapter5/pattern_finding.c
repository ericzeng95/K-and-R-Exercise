/* write the code of pattern finding program in the book, */
/* not an exercise. */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern, only one argument\n");
    } else {
        while (getLine(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }
}

/* getline: get line into s, return length */
int getLine(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
