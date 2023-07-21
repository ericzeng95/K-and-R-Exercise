/* a program that reverse character string s */
#include <stdio.h>
#define MAXCHAR 100

int getLine(char line[], int maxLine);

int main() {
    int c;
    int i = 0;
    char line[MAXCHAR];
    char revline[MAXCHAR];
    while ((c = getchar()) != EOF && c != '\n') {
	line[i++] = c;
    }
    int k = i - 1;
    // total char in line: i - 1
    for (k = i - 1; k >= 0; k--) {
	revline[i - 1 - k] = line[k];
    }
	revline[i] = '\0';

	printf("%s\n", revline);
}
