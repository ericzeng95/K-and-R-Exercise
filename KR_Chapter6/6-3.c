/* exercise 6-3: Write a cross-referencer that prints a list of all words in a
 * document, and for each word, a list of the line numbers on which it occurs.
 * Remove noise words like ``the,'' ``and,'' and so on. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 20

struct tnode *addTree(struct tnode *, char *, int);
void tree_print(struct tnode *);
struct tnode {
    char *word;
    // int count;
    int line_list[100]; // assume the word occurs at most 100 times
    int line_count;
    struct tnode *left;
    struct tnode *right;
};

int main(int argc, char *argv[]) {
    char *fileName = argv[1]; // fileName is only argument
    FILE *f = fopen(fileName, "r");
    char line[200];     // maximum read 200 characters per line
    char *linep = line; // pointer of line
    int lineNo = 1;

    struct tnode *root;
    root = NULL;

    while (fgets(line, sizeof(line), f)) {
        char *word = strtok(line, " ");
        while (word) {
            char last = word[strlen(word) - 1];
			if (last == '\0') break;
            if (!((last >= 'A' && last <= 'Z') ||
                  (last >= 'a' && last <= 'z'))) {
                word[strlen(word) - 1] = '\0';
				continue;
            }
            root = addTree(root, word, lineNo);
            word = strtok(NULL, " ");
        }
        lineNo++;
    }
    tree_print(root);
    fclose(f);
    return 0;
}

char *strdUp(char *);

struct tnode *talloc(void);
/* trying to add the word to the tree */
/* if there is matching, add counter by 1, otherwise create a child node */
/* at the bottom */
struct tnode *addTree(struct tnode *p, char *w, int lineNo) {
    int cond;
	*w = tolower(*w);
    if (!p) {
        p = talloc(); // assign a new
        p->word = strdUp(w);
        p->line_list[p->line_count++] = lineNo;
        p->left = NULL;
        p->right = NULL;
    } else if (((cond = strcmp(p->word, w)) == 0)) {
        p->line_list[p->line_count++] = lineNo;
    } else if (cond < 0) {  // cond < 0: p.word < w, add to right
        p->right = addTree(p->right, w, lineNo);
    } else {
        p->left = addTree(p->left, w, lineNo);
    }
    return p;
}

/* create the space for a new node */
struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* strdup copies string in argument into a safe space */
char *strdUp(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1); // you need +1 for '\0'
    if (p)
        strcpy(p, s);
    return p;
}

/* print a tree in order */
void tree_print(struct tnode *p) {
    if (p) {
        tree_print(p->left);
        printf("%s: [", p->word);
        for (int i = 0; i < sizeof(p->line_list) / sizeof(p->line_list[0]);
             i++) {
            if (p->line_list[i] != 0) {
                printf("%d", p->line_list[i]);
                if (i != p->line_count - 1)
                    printf(", ");
            }
        }
        printf("]\n");
        tree_print(p->right);
    }
}

