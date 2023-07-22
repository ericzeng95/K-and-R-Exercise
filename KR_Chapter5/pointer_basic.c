/* practice some pointer basic */
#include <stdio.h>

int arrlen(char *);

int main() {
    int x = 1, y = 2, z[10];
	char s[] = "asdjkl";
	int *ip; // a pointer to a int
	ip = &x; // ip points to x now
	printf("%d\n", *ip);
	y = *ip; // assign y's value to ip's pointing to (x's value), y is 1 now
	printf("%d\n", y);
	*ip = 0; // x to 0		
	printf("%d\n", x);
	ip = &z[0]; // re-point ip to first element of z;
	printf("%d\n", *ip);
	
	printf("length of z using pointer: %d\n", arrlen(s));
}

int arrlen(char *arr){
	char *p = arr;
	while (*p != '\0') {
		p++;
		printf("debug p: %d\n", *p);
	}
	return p - arr;
}
