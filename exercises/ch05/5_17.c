#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define MDIR 8
#define LINES 100
#define MAXSTR 100
#define MAXLINES 500 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void error(char *);
void _qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));
void readargs(int argc, char *argv[]);
int charcmp(char *,char *);
int numcmp(char *, char *);

int option = 0;

int pos1 = 0;   /* field begining with pos 1 */
int pos2 = 0;   /* ending just before pos 2 */

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
	int c,rc = 0;
   
	 
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if(option & NUMERIC){
			_qsort((void**) lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
		}
		else{
	    	_qsort((void**) lineptr, 0, nlines - 1, (int (*) (void *, void *)) charcmp);		
		}
		writelines (lineptr, nlines);
	return 0;
    } else {
	printf ("input too big to sort\n");
	return 1;
    }
	
	return rc;
}

void readargs(int argc,char *argv[])
{
	int c;		
	 while(--argc > 0 && (c = (*++argv)[0]) == '-' ||c == '+')
	 {
	   if(c=='-' && !isdigit(*(argv[0]+1))){
		while(c=*++argv[0]){
			switch(c){
				case 'd':
					option !=MDIR;
					break;
				case 'f':
					option !=FOLD;
					break;
				case 'n':
					option !=NUMERIC;
					break;
				case 'r':
					option !=DECR;
					break;
				default:
					  printf("sort: illegal option %c \n",c);
                    error("Usage: sort -dfnr [+pos1] [-pos2]");
					argc = 1;				
					break;
			}
			}
			}
			else if(c=='-')
				pos2 = atoi(argv[0]+1);
			else if((pos1=atoi(argv[0]+1))<0)
				error("usage:sort -dfnr [+pos1][-pos2]");;
		}	
	if(argc||pos1>pos2)
		error("usage:sort -dfnr [+pos1][-pos2]");
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp) (void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
	return ;       /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
	if ((*comp) (v[i], v[left]) < 0)
	    swap(v, ++last, i);
    }
    swap(v, left, last);
    _qsort(v, left, last - 1, comp);
    _qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
   double v1,v2;
    char str[MAXSTR];

    substr(s1,str,MAXSTR);
    v1 = atof(str);

    substr(s2,str,MAXSTR);
    v2 = atof(str);

    if(v1 < v2)
        return -1;
    else if ( v1 > v2)
        return 1;
    else
        return 0;
}


int charcmp(char *s,char *t)
{
	char a, b;
	int i,j,endpos;
	extern int option,pos1,pos2;
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & MDIR) ? 1 : 0;
	i = j = pos1;
	
	if(pos2>0)
		endpos = pos2;
	else if((endpos= strlen(s))>strlen(t))
		endpos = strlen(t);	
	do {
	if (dir) {
	 while(i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
     i++;
    while(j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
     j++;
	}
	if(i<endpos && j<endpos){
		a = fold ? tolower(s[i]) : s[i];
		i++;
		b = fold ? tolower(t[j]) : t[j];
		j++;
		if (a == b && a =='\0')
		return 0;
	  }
	}while (a == b && i<endpos && j<endpos);
	return a -b;
}

void substr(char *s,char *str);
void substr(char *s,char *str)
{
	int i,j,len;
	extern int pos1,pos2;
	len = strlen(s);
	if(pos2>0&&len>pos2)
		len = pos2;
	else if(pos2>0&& len <pos2)
		error("substr:string too short.\n");
	for(j=0,i=pos1;i<len;i++,j++)
		str[j] = s[i];
	str[j]='\0';
}

//errror: prints the error message
 void error(char *s)
 {
  printf("%s\n",s);
  exit(1);
 }

int getline(char s[], int line)
{
int c, i, j;
for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n'; ++i)
{
if(i < line - 1)
{
s[j++] = c;
}
}
if(c == '\n')
{
if(i <= line - 1)
{
s[j++] = c;
}
++i;
}
s[j] = '\0';
return i;
}

#define MAXLEN 1000

char *alloc(int n);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
	if (nlines >= maxlines || (p = alloc(len)) == NULL)
	    return -1;
	else {
	    line[len - 1] = '\0'; /* delete newline */
	    strcpy (p, line);
	    lineptr[nlines++] = p;
	}
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
	printf ("%s\n", lineptr[i]);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
	allocp += n;
	return allocp - n; /* old p */
    } else
	return 0;
}
