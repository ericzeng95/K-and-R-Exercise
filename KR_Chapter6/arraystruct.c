/* practice array of struct */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEY 100

int getWord(char *, int);
int binSearch(char *, struct key *, int);

struct key {
    char *word;
    int count;
} keytab[] = {"auto",  0, "break",    0, "case",    0, "char",     0,
              "const", 0, "continue", 0, "default", 0, "unsigned", 0,
              "void",  0, "volatile", 0, "while",   0};

int main(){
	return 0;
}
