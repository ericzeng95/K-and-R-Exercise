/* Table lookup program */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nList {
    struct nList *next;
    char *name; // defined name
    char *defn; // text to replace
};

#define HASHSIZE 101

static struct nList *hashTab[HASHSIZE]; // table of pointers

/* hash: generate hash value (int) for string s */
unsigned int hash(char *s) {
    unsigned int hashVal;

    for (hashVal = 0; *s != '\0'; s++)
        hashVal = *s + 31 * hashVal;
    return hashVal % HASHSIZE;
}

/* lookup value in a hashTab. input a string and return the */
/* pointer to the hashTab */
struct nList *lookup(char *s) {
    struct nList *np;
    for (np = hashTab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

char *strdUp(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1); // you need +1 for '\0'
    if (p)
        strcpy(p, s);
    return p;
}
/* enter new definition, if there is existing definition, overwrite it, */
/* otherwise, create new space for definition. */
struct nList *install(char *name, char *defn) {
    struct nList *np;
    unsigned int hashVal;

    if ((np = lookup(name)) == NULL) {
        // not found, create new
        np = (struct nList *)malloc(sizeof(struct nList));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            // no space
            return NULL;
        }
		hashVal = hash(name);
		np->next = hashTab[hashVal];
		hashTab[hashVal] = np;
    } else {
		// existing hash value
		free((void *) np->defn); // free previous definition
    }
	if ((np->defn = strdUp(defn))==NULL) {
		// try to assign new definition space
		// but also check if there is enough space
		return NULL;
	}
	return np;
}

int main(){
	// manually test out some
	struct nList *temp;

	temp = install("test", "TTTT");
	temp = install("test", "PPPP");
	temp = install("make", "PPPP");
	temp = install("deal", "asdl");

	printf("test: %s\n", lookup("test")->defn);
	printf("make: %s\n", lookup("make")->defn);
	printf("deal: %s\n", lookup("deal")->defn);
}
