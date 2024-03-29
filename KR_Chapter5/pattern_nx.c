/* implement pattern find with parameter -n and x */
/* -n: print line number for non-matches */
/* -x: inverse finding to non-finding */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char *, int);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    // there is still argument, and first
    // letter argument is - sign
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("Find: illegal option %c\n", c);
                argc = 0; // reset argc
                found = -1;
                break;
            }

    if (argc != 1) {
        printf("Wrong syntax: do find -x -n pattern\n");
    } else {
        while (getLine(line, MAXLINE)) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
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
