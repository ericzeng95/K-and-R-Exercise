/* 4-1 write function strindex(s,t) which returns position */
/* of right most occurence of t in s or -1 if none */
#include <stdio.h>
#define MAX 100

int strindex(char[], char);

int main(){
	char s1[MAX];

	char c;
	int i = 0;
	while ((c=getchar()) && i<MAX && c!=EOF && c!='\n') {
		s1[i++] = c;
	}
	char t = getchar();
	int v = strindex(s1, t);

	printf("%d\n", v);
}

int strindex(char s[], char t){
	int v = -1;

	for (int i=0; s[i] !='\0'; i++) {
		if (s[i] == t) {
			v = i;
		}
	}
	return v;
}
