/* write a program to print distinct words in input sorted into decreasing
 * order of frequency, print first word then count */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct word_count {
    char *word;
    int count;
};
struct word_count wcArray[MAXWORD];
int totalWord = 0;

int getword(char *, int);
void addWordCount(char *);
void swap(struct word_count *, struct word_count *);
void quick_sort(struct word_count *, int, int);

int main() {
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            addWordCount(word);
        }
    }
    // testing swapping first and second
    // swap(&wcArray[0], &wcArray[1]);
    quick_sort(wcArray, 0, totalWord - 1);
    for (int i = 0; i < totalWord; i++) {
        printf("%s: %d\n", wcArray[i].word, wcArray[i].count);
    }
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

/* create space for a new node */
struct word_count *talloc(void) {
    return (struct word_count *)malloc(sizeof(struct word_count));
}

/* strdup copies string in argument into a safe space */
char *strdUp(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1); // you need +1 for '\0'
    if (p)
        strcpy(p, s);
    return p;
}

void addWordCount(char *w) {
    int cond;
    for (int i = 0; i < totalWord; i++) {
        if ((cond = strcmp(w, wcArray[i].word)) == 0) {
            wcArray[i].count++;
            return;
        }
    }
    // no match, create a new one
    wcArray[totalWord].word = strdUp(w);
    wcArray[totalWord++].count = 1;
}

void swap(struct word_count *a, struct word_count *b) {
    // swap two elements in an array of struct word_count
    struct word_count tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(struct word_count *wc, int start, int end) {
    int v_pivot = wc[end].count;

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (wc[j].count >= v_pivot) {
            i++;
            swap(&wc[i], &wc[j]);
        }
    }
    swap(&wc[i + 1], &wc[end]);
    return (i + 1);
}

void quick_sort(struct word_count *wc, int start, int end) {
    if (start < end) {
        int pivot_position = partition(wc, start, end);
        quick_sort(wc, start, pivot_position - 1);
        quick_sort(wc, pivot_position + 1, end);
    }
}
