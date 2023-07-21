/* K and R Exercise 2-3 */
/* write a squeeze(s1, s2) that deletes each char in s1 that matches any char in
 * s2 */
#include <stdio.h>

#define MAX 100
char input[MAX];
void squeeze(char s1[], char s2[]);

int main() {
    extern char input[];
    /* printf("%d\n", htoi()); */
    char s1[] = "hello";
    char s2[] = "el";
    squeeze(s1, s2);
    printf("%s\n", s1);
	printf("Test string\n");
	
}

void squeeze(char s1[], char s2[]) {
    int no_found = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        int found = 0;
        for (int j = 0; (s2[j] != '\0') && (found == 0); j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                no_found += 1;
            }
        }
        if (!found) {
            s1[i - no_found] = s1[i];
        }
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i + no_found] == '\0')
            s1[i] = '\0';
    }
}
