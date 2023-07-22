/* 5-4 write stringEnd(s, t) return 1 if string t occur at end of s, 0 otherwise
 */

#include <stdio.h>
int strEnd(char *, char *);
int strLen(char *);

int main() {
    char s[] = "test123";
    char t[] = "123";
    char f[] = "234";

    printf("test 1: %d\n", strEnd(s, t));
    printf("test 1: %d\n", strEnd(s, f));
}

int strEnd(char *s, char *f) {
    // move s forwar by length difference
    s += strLen(s) - strLen(f);
	while (*s && *s++ == *f++) ;
	return !*s;
}

int strLen(char *s) {
    // get length of string
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}
