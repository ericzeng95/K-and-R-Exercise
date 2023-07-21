/* write a program for function lower (changing upper cases to lower cases) without using if-else */
#include <stdio.h>
#define MAX 100
char input[MAX];
void getLine();
void lower(char s[]);

int main(){
	extern char input[];
	getLine();
	lower(input);
	printf("%s\n", input);
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

void lower(char s[]){
	for (int i=0; s[i] != '\0'; i++){
		s[i] = ((s[i] >= 'A') && (s[i] <= 'Z') ) ? (s[i] - ('A' - 'a')) : s[i];
	}
}

