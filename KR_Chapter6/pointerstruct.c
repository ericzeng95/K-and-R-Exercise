/* rewrite the arraystruct.c using pointer to struct */
/* practice array of struct */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXWORD 100
#define NKEY (sizeof keytab / sizeof(keytab[0]))

struct key {
    char *word;
    int count;
} keytab[] = {"auto",  0, "break",    0, "case",    0, "char",     0,
              "const", 0, "continue", 0, "default", 0, "unsigned", 0,
              "void",  0, "volatile", 0, "while",   0};

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* count C keywords */
int main() {
    struct key *p;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p = binsearch(word, keytab, NKEY)) != NULL) {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEY; p++)
        /* if (p->count>0) */
        printf("%4d  %s \n", p->count, p->word);
    return 0;
}

// binary search, find the word between
// tab[0] and tab[n-1]
struct key *binsearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low <= high) {
        /* mid = (low + high) / 2; // pointer cannot be added directly to
         * another pointer */
        mid = low + (high - low) / 2; // however, you can add the diff between
                                      // pointers (since it's int)
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

/* a more general getword that fetches thee next word from input */
/* when a word is a string of letters and digits beginning with a letter */
/* or single non-white space char. */
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
