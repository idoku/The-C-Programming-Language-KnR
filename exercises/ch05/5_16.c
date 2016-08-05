#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define MDIR 8
#define LINES 100

#define MAXLINES 500 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void _qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *));

int dircmp(char *,char *);
int numcmp(char *, char *);

static char option = 0;
/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
	int c,rc = 0;
    while(--argc>0 && (*++argv[0]=='-')){
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
					printf("sort:illigal option %c\n",c);
					argc = 1;
					rc = -1;
					break;
			}
		}
	}
	if(argc)
		printf("Usage:sort -dfnr \n");
	else{
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if(option & NUMERIC){
			_qsort((void**) lineptr, 0, nlines - 1, (int (*) (void *, void *)) numcmp);
		}
		else{
	    	_qsort((void**) lineptr, 0, nlines - 1, (int (*) (void *, void *)) dircmp);		
		}
		writelines (lineptr, nlines);
	return 0;
    } else {
	printf ("input too big to sort\n");
	return 1;
    }
	}
	return rc;
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
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    return v1 - v2;
}


int dircmp(char *s1,char *s2)
{
	char a, b;
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & MDIR) ? 1 : 0;
	do {
	if (dir) {
	while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
		s1++;
	while (!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
		s2++;
	}
	a = fold ? tolower(*s1) : *s1;
	a = *s1;
	s1++;
	b = fold ? tolower(*s2) : *s2;	
	s2++;
	if (a == b && a =='\0')
	return 0;
	}while (a == b);
	return a -b;
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
