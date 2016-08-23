#include <stdio.h>
#include <string.h>
 #include <stdlib.h>
 
#define HASHSIZE 101

struct nlist{ /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name  */
	char *defn; /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */
   
struct nlist *install(char *,char *);
struct nlist *lookup(char *);
unsigned hash(char *);
void display_entry(int index);

int main()
{
	int i;
	install("MAX_SIZE","100");
	install("MIN_SIZE","0");
	install("COUNT","5");
	for(i=0;i<HASHSIZE;i++)
		display_entry(i);
	return 0;
}

void display_entry(int index)
{
	struct nlist *np;
	for(np = hashtab[index];np!=NULL;np=np->next)
		printf("[%2d]\tname (%s) -- defn(%s)\n",index,np->name,np->defn);
}

 /* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0;*s != '\0' ; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}


    /* lookup: look up s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for(np = hashtab[hash(s)];np != NULL; np = np->next)
		if(strcmp(s,np->name)==0)
			return np; /* found */
	return NULL;   /* not found */
}


 /* install: put(name,defn) in hashtab */
struct nlist *install(char *name,char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if((np=lookup(name))==NULL) { /* not found */
		np = (struct nlist *)malloc(sizeof(*np));
		if( np == NULL || (np->name = strdup(name))==NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else{ /* already there */
		free((void*)np->defn); /* free previous defn */
	}
	if((np->defn = strdup(defn))==NULL)
		return NULL;
	return np;
}



#define BUFSIZE 100

int buffer[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
	buffer[bufp++] = c;
    else
	printf ("error: buffer is full\n");
}
