/* 5-3 write a pointer version of strcat to copy s2 to end of s1 */
#include <stdio.h>
void concatStr(char *, char *);

int main(){
	char s1[] = "test";
	char s2[] = "add";
	concatStr(s1, s2);
	printf("%s\n", s1);
}


void concatStr(char *s1, char *s2){
	while (*s1) {
		s1++;
	}
	while (*s1++ = *s2++) ;
}
