/* practice some pointer basic */
#include <stdio.h>

int strlen(char *);

int main(){
	printf("%d", strlen("adkjkadjal"));
}

int strlen(char *s){
	// calcculate length of string
	int n;
	for (n=0; *s != '\0'; s++){
		n++;
	}
	return n;
}
