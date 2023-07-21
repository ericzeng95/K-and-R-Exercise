/* K and R Exercise 2-3 */
/* convert hex digit to integer value */
#include <stdio.h>

#define MAX 100
char input[MAX];
void getLine();
int htoi();

int main() {
    extern char input[];
    getLine();
    printf("%d\n", htoi());
}

void getLine() {
    extern char input[];
    int c, i;
    i = 0;
    while ((c = getchar()) && i < MAX && c != EOF && c != '\n') {
        input[i] = c;
        ++i;
    }
    return;
}

int digit(char d) {
    if (d >= '0' && d <= '9')
        return d - '0';
    else
        return (d - 'A' + 10);
}

int htoi() {
    /* convert a string of hex (w/, w/o 0x or 0X) to integer value */
    extern char input[];
    int value = 0;
    /* int len = sizeof(input) / sizeof(input[0]); */
    /* rewrite the way of getting length. */
    int len = 0;
    for (int k = 0; input[k] != '\0'; ++k) {
        len += 1;
    }

    int startIndex;
    if (len <= 2) {
        return (16 * digit(input[0]) + digit(input[1]));
    } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        startIndex = 2;
    } else {
        startIndex = 0;
    }
    for (int i = startIndex; i < len; i++) {
        int v = digit(input[i]);
        for (int j = i; j < len - 1; j++) {
            v = v * 16;
        }
        value = value + v;
    }
    return value;
}

