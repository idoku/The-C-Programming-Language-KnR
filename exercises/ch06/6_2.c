
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode{        /* the tree node; */
	char *word;      /* points to the text */
	int count;        /* number of occurrences */	
	struct tnode *left;     /*  left child  */
	struct tnode *right;    /* right child */
};

/*
	simroot:part of a linked list of pointers to simword lists with
	a common root.
*/
struct simroot{
	struct simword *firstword; //points to the list of words
	struct simroot *nextroot; //points to the next node in the list
};

/*
	simword:part of a linked list of words with a common root.
	points to the word in the tnodes.
*/
struct simword{
	char *word;//points to the word in the tree
	int count; //copied from the tree 
	struct simword *nextword; // next node;
};
		
struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode *);
int getword(char *,int);
struct simword *walloc(struct simword *,struct tnode *);
struct simroot *addroot(struct simroot *,struct tnode *,int);
void addword(struct simword *,struct tnode *);
struct simroot *parse(struct tnode*,int);
void printlist(struct simroot *,int);
void printwords(struct simword *);
void ungetch(int c);
int getch(void);
// char *strdup(char *s);

/* word frequency count */
int main(int argc,char *argv[])
{
	int len=3;
	struct tnode *root;
	struct simroot *listroot;
	char word[MAXWORD];
	root = NULL;
	while(getword(word,MAXWORD)!=EOF)
		if(isalpha(word[0]))
			root = addtree(root,word);
			
	if(argc == 1)
        len = 3;
    else if(argc == 2)
        len = atoi(argv[1]);
    else {
        printf("Incorrect number of arguments.\n");
        return 1;
    }

	listroot = NULL;
	listroot = parse(root,len);
	treeprint(root);
	printf("\nDuplicate list:\n\n");
	printlist(listroot,len);
	return 0;
}

struct simroot *parse(struct tnode *node,int len)
{
	struct tnode *temp;
	int this_len;
	static struct simroot *root = NULL;
	
	if(node==NULL)
		return NULL;
	
	this_len = strlen(node->word);
	parse(node->left,len);	 
	temp = node->left;
	if(temp!=NULL){
		while(temp->right!=NULL)
			temp=temp->right;
		if(this_len >=len && strncmp(temp->word,node->word,len)==0){
			root = addroot(root,temp,len);
			addroot(root,node,len);
		}
	}
	
	temp = node->right;
	if(temp!=NULL){
		while(temp->left!=NULL)
			temp = temp->left;
		if(this_len>=len && strncmp(temp->word,node->word,len)==0){
			root = addroot(root,node,len);
			addroot(root,temp,len);
		}
	}
	
	parse(node->right,len);
	
	return root;
}

struct simroot *addroot(struct simroot *p,struct tnode *n,int len)
{
	if(p==NULL){
		p = (struct simroot *)malloc(sizeof(struct simroot));
		p->nextroot = NULL;
		p->firstword = walloc(p->firstword,n);
	}
	else if(strncmp(p->firstword->word,n->word,len)==0)
		addword(p->firstword,n);
	else
		p->nextroot = addroot(p->nextroot,n,len);
	return p;
}

void addword(struct simword *p,struct tnode *n)
{
	if(strcmp(p->word,n->word)==0)
		return;
	if(p->nextword==NULL)
		p->nextword = walloc(p->nextword,n);
	else
		addword(p->nextword,n);
}

struct simword *walloc(struct simword *p,struct tnode *n)
{
	p = (struct simword *)malloc(sizeof(struct tnode));
	if(p!=NULL){
		p->word = n->word;
		p->count = n->count;
		p->nextword = NULL;
	}
	return p;
}

void printlist(struct simroot *p,int len)
{
	int i;
	if(p==NULL)
		return;
	for(i=0;i<len;i++)
		putchar(p->firstword->word[i]);
	putchar('\n');
	printwords(p->firstword);
	printlist(p->nextroot,len);
}

void printwords(struct simword *p)
{
	printf(" %4d %s\n",p->count,p->word);
	if(p->nextword!=NULL)
		printwords(p->nextword);
}




struct tnode *talloc(void);

/* addtree: add a node with w,at or below p */
struct tnode *addtree(struct tnode *p,char *w)
{
	int cond;
	if( p == NULL){ /* a new word has arrived */
		p = talloc();  /* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}else if((cond = strcmp(w,p->word))==0)
		p->count++; /* repeated word */
	else if(cond < 0) /* less than into subtree */
		p->left  = addtree(p->left,w);
	else  /* greater than into right subtree */
		p->right = addtree(p->right,w);
	return p;
}
	
/* treeprint:in-order print of tree p */
void treeprint(struct tnode *p)
{
		if(p!=NULL)
		{
			treeprint(p->left);
			printf("%s\n",p->word);
			treeprint(p->right);
		}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}



/* getwod: get next word or character from inpt */
int getword(char *word,int lim)
{
	int c,d,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c=getch()))
		;
	if(c!=EOF)
		*w++=c;
	if(!isalpha(c) || c =='-' || c=='#')
	{
		for(;--lim>0;w++){
			if(!isalnum(*w=getch()) && *w!='-'){
				ungetch(*w);
				break;
			}
		}		
	}
	else if(c=='\''||c=='\\')
	{
		for(;--lim>0;w++){
			if((*w=getch())=='\\')
				*++w = getch();
			else if(*w==c){
				w++;
				break;
			}
			else if(*w==EOF)
				break;
		}
	}
	else if(c=='/'){
		if((d=getch())=='*')
		   c = comment();
		else
			ungetch(d);
	}	
	*w='\0';
	return c;
}

int comment()
{
	int c;
	while((c=getch())!=EOF)
	{
		if(c=='*')
		{
			if((c=getch())=='/')
				break;
		}else{
			ungetch(c);
		}
	}
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;


int getch(void)     /* get a(possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] =c;
}

// char *strdup(char *s) /* make a duplicate of s */
// {
	// char *p;
	// p = (char *)malloc(strlen(s)+1); /* +1 for '\0' */
	// if(p!=NULL)
		// strcopy(p,s);
	// return p;
// }
