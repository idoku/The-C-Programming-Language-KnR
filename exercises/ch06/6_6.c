/*
	Exercise 6-5. Write a function undef that will remove a 
	name and definition from the table maintained by lookup and install.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist{ /* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name; /* defined name  */
	char *defn; /* replacement text */
};

enum { NAME, DEFINE };

#define HASHSIZE 5

static struct nlist *hashtab[HASHSIZE]; /* pointer table */
   
struct nlist *install(char *,char *);
struct nlist *lookup(char *);
unsigned hash(char *);
void display_entry(int index);
void undef(char *s);
int getword(char *word,int limits);
void ungetch(int c);
int getch(void);

#define MAXLEN 200

int main()
{
	int i,c;
	char w[MAXLEN],name[MAXLEN];
	char defn[MAXLEN*15];
	
	for(c=getword(w,MAXLEN);c!=EOF;c=getword(w,MAXLEN)){
		if(c==DEFINE){
			c = getword(w,MAXLEN);
			if(c!=NAME){
				printf("error:name spected\n");
			}
			strcpy(name,w);
			_getline(defn,MAXLEN*15);
			install(name,defn);
		}
	}
	
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

void undef(char *s)
{
   struct nlist *np,**prev;
   unsigned hashval = hash(s);
   for(prev = &hashtab[hashval],np= hashtab[hashval];
	np!=NULL && strcmp(s,np->name);prev=&np->next,np=np->next) 
	;
	if(np==NULL)
		return;
	*prev = np->next;
	free(np);
}

int getword(char *word,int limits)
{
	int c;
	char *w = word;
	while((c=getch())==' '|| c=='\t')
		;
	*w++ = c;
	if(!isalpha(c) && c!='_' && c!='#'){
		*w='\0';
		return c;
	}
	
	while(w<word+limits-1 && (isalpha(c=*w++=getch()) || c=='_'))
		;
	*--w='\0';
	ungetch(c);
	return (!strcmp(word,"#define"))?DEFINE:NAME;
}

int _getline(char *line,int limits)
{
	char *s = line;
	for(;s<line+limits-1 && (*s=getch())!='\n' && *s!=EOF;s++)
		;
	*s='\0';
	return s-line;
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
