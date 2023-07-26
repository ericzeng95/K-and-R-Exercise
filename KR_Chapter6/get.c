#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	// void means no function argument
	return (bufp >0)? buf[--bufp]:getchar();
}

void ungetch(int c){
	if (bufp > BUFSIZE) {
		printf("too many buffer \n");
	} else {
		buf[bufp++] = c;
	}
}
