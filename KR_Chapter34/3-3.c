/* 3-3 write a function expand(s1, s2) that expadns shorthand notations */
/* like a-z in the string s1 to the equivalent complete list in s2. */
/* allow both letter and digit, and be prepared to handle cases like a-b-c */
/* and a-z0-9 and -a-z. */ 

#include <stdio.h>
#define MAX 100

void expand(char s1[], char s2[]);
char dtype(char c);

char s1[MAX];
char s2[MAX];

int main(){
	extern char s1[];
	extern char s2[];

	char c;
	int i = 0;
	while ((c=getchar()) && i<MAX && c!=EOF && c!='\n') {
		s1[i++] = c;
	}

	expand(s1, s2);
	printf("%s\n", s2);
}

void expand(char s1[], char s2[]){
	// s1 = a-d
	// s2 = abcd
	int stage = 0; // 0: begin, 1: dash, 2: end
	int charCount = 0;

	int begin, end;

	int size1 = sizeof(s1) / sizeof(char);
	int size2 = sizeof(s2) / sizeof(char);

	for (int i=0; i < size1; i++) {
		if (stage == 0) {
			if (s1[i] == '-') {
				// if begin but dash, record dash literally
				s2[charCount++] = s1[i];
			} else {
				begin = s1[i];
				stage = 1; // stage move from 0 to 1
			}
		} else if (stage == 1) { // expecting dash
			if (s1[i] != '-') {
				// not dash, previous begin is invalid,
				// record old begin literally, and
				// make current position new begin
				s2[charCount++] = begin;
				begin = s1[i];
			} else {
				stage = 2; // stage move from 1 to 2
			}
		} else { // stage 3
			if (s1[i] == '-') {
				// not correct end
				// record old begin, dash, and this dash
				// restart
				s2[charCount++] = begin;
				s2[charCount++] = '-';
				s2[charCount++] = '-';
			} else {
				// check if begin and end is same dtype
				end = s1[i];
				if (dtype(begin) == dtype(end)){
					for (int c=begin; c<=end; c++) {
						s2[charCount++] = c;
						stage = 0; // finish task, go back to stage 0
					}
				} else {
					s2[charCount++] = begin;
					s2[charCount++] = '-';
					begin = end;
					stage = 1;
				}
			}
		}
	}
}

char dtype(char c){
	/* get the dtype (digit, lower, upper) of the char */
	if (c >= 'a' && c <= 'z') {
		return 'l';
	} else if (c >= 'A' && c <= 'Z') {
		return 'u';
	} else if (c >= '0' && c <= '9') {
		return 'd';
	}
}
