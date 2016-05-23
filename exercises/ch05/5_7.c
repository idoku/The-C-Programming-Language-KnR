/*
 *Exercise 5-7.Rewrite readlines to store lines in an array supplied by 
 *main,rather than calling alloc to maintain storage.How much faster is 
 *the program?
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 /* max length of any input line */
#define MAXLINES 5000 /* max #line to be sorted */

int readlines(char *lineptr[], char buffer[], int nlines);
int getline(char *,int);
void writelines(char *lineptr[],int nlines);

#define BUFSIZE 1000 /* size of available space */
char *lineptr[MAXLINES]; /* pointers to text lines */

int main()
{
	int nlines; /* number of input lines read */
	char buffer[MAXLEN];
	if((nlines=readlines(lineptr,buffer,MAXLINES))>=0){		
		writelines(lineptr,nlines);
		return 0;
	}
	else{
		printf("error:input too big\n");
		return 1;
	}
	return 0;
}

/* readlines:read input lines */
int readlines(char *lineptr[],char buffer[],int maxlines)
{
	int len,nlines;
	char *bufp,line[MAXLEN];	
	nlines=0;
	bufp = buffer;
	while((len=getline(line,MAXLEN))>0){
		 if(nlines>maxlines || buffer+BUFSIZE-bufp<len)
			return -1;
		 line[len-1] = '\0';
		 strcpy(bufp,line);
		 lineptr[nlines++] = bufp;
		 bufp+=len;
		 }
		return nlines;
}

/* getline:read a line into s,return length */
int getline(char s[],int lim)
{
    int c,i;
    for(i = 0;i <lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;   
    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* writelines:write output lines */
void writelines(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);
}
