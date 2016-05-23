/*
 *Exercise 4-1. Write the function strrindex(s,t),which returns the position of 
 *the rightmost occurrence of t in s,or -1 if there is none.
*/

#include <stdio.h>

#define MAXLINE 1000   /* maximum input line length */

int getline(char line[],int max);
int strrindex(char s[],char t[]);

char pattern[] = "ould"; /* pattern to search for */

int main()
{
	char line[MAXLINE];
	int found = 0;
	while(getline(line,MAXLINE)>0){
		if(strrindex(line,pattern)>=0){
			printf("%s",line);
			found++;
		}
	}
  return found;
  return 0;
}

/* strindex: return index of t in s,-1 if none */
int strrindex(char s[],char t[])
{
	int i,j,k,m=0,n=0;
	while(s[m]!='\0')
		m++;
	while(t[n]!='\0')
		n++;
	for(i=m-n;s[i]!='\0';i--){	   
		for(j=i,k=0;t[k]!='0'&& s[j]==t[k];k++,j++){
			;		
		}		
		if (j > 0 && t[j] == '\0') {
			return i;
		}
	}
	return -1;
}

/* getline: get line into s,return length */
int getline(char s[],int lim)
{
	int c,i;
	i = 0;
	while(--lim>0&& (c=getchar())!=EOF && c!='\n')
		s[i++] = c;
	if(c=='\n')
		s[i++] = c;
	s[i]='\0';
	return i;
}




