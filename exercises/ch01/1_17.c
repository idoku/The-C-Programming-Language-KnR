/*
 * Exercise 1-17. Write a program to print all input 
 * lines that are longer than 80 characters.
*/

#include "stdio.h"

#define MAXINLINE 1000  /* maximum line sizes defined*/
#define LONGLINESIZE  80     /* longer line defined as 80 */

int getline(char line[],int maxline);
/*print lines longer than LONGLINESIZE     */
int main()
{
	 int len;           /*current line length */
	 char line[MAXINLINE];/* current input line */
	 while((len=getline(line,MAXINLINE))>0)
	  if(len> LONGLINESIZE)
	   printf("%s", line);
	 return 0; 
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