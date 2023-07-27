/* rewrite the arraystruct.c using pointer to struct */
/* practice array of struct */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode *addTree(struct tnode *, char *);
void tree_print(struct tnode *);

struct tnode{
	char *word; // the text of the node
	int count; // count of the node
	struct tnode *left; // pointer to left child
	struct tnode *right; // pointer to right child
};

int getword(char *, int);

int main(){
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD)!= EOF) {
		if (isalpha(word[0])) {
			root = addTree(root, word);
		}
	}
	tree_print(root);
	return 0;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word; // assign a pointer that points to word

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0]; // return first letter of word
}

struct tnode *talloc(void);
char *strdUp(char *);
/* trying to add the word to the tree */
/* if there is matching, add counter by 1, otherwise create a child node */
/* at the bottom */
struct tnode *addTree(struct tnode *p, char *w){
	int cond; 

	if (!p) {
		p = talloc(); // assign a new 
		p->word = strdUp(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	} else if ((cond = strcmp(p->word, w)==0)) {
		p->count++;
	} else if (cond < 0) {
		p->left = addTree(p->left, w);
	} else {
		p->right = addTree(p->right, w);
	}
	return p;
}


/* create the space for a new node */
struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup copies string in argument into a safe space */
char *strdUp(char *s){
	char *p;
	p = (char *) malloc(strlen(s)+1); // you need +1 for '\0'
	if (p)
		strcpy(p, s);
	return p;
}

/* print a tree in order */
void tree_print(struct tnode *p){
	if (p){
		tree_print(p->left);
		printf("%4d %s\n", p->count, p->word);
		tree_print(p->right);
	}
}
