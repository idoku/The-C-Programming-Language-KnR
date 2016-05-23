#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 1000/* max #line to be sorted */
#define MAXLEN 1000 /* max length of any input line */
#define ALLOCSIZE 1000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* size of available space */
static char *allocp = allocbuf; /* next free position */
char *lineptr[MAXLINES]; /* pointers to text lines */
char *lineptr[MAXLINES]; /* pointers to text lines */
char lines[MAXLINES][MAXLEN];
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int start,int nlines);
int getline(char s[], int line);
char *alloc(int n);
/* sort input lines */
int main(int argc,char *argv[])
{
int n = 10;
while(--argc>0){
char *arg = *++argv;
n = atoi(++arg);
}
int nlines; /* number of input lines read */
int start = 0;
if((nlines=readlines(lineptr,MAXLINES))>=0){
if(nlines>n){
start = nlines-n;
}
writelines(lineptr,start,nlines);
return 0;
}
else{
printf("error:input too big to sort\n");
return 1;
}
printf("%d\n",nlines);
return 0;
}
/* writelines:write output lines */
void writelines(char *lineptr[],int start,int nlines)
{
int i;
for(i=start;i<nlines;i++)
printf("%s\n",lineptr[i]);
}
/* readlines:read input lines */
int readlines(char *lineptr[],int maxlines)
{
int len,nlines;
char *p,line[MAXLEN];
nlines=0;
while((len=getline(line,MAXLEN))>0)
if(nlines>=maxlines||(p=alloc(len))==NULL)
return -1;
else{
line[len-1] = '\0'; /* delete newline */
strcpy(p,line);
lineptr[nlines++] = p;
}
return nlines;
}
char *alloc(int n)
{
if(allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
{
allocp += n;
return allocp - n; /* old p */
}
else /* not enough room */
{
return 0;
}
}
/* getline: read a line into s, return length */
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