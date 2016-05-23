/*
 * Exercise 1-19. Write a function reverse(s) that reverses 
 * the character string s.Use it to write a program that 
 * reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline(char line[],int maxline);
void reverses(char line[]);

int main()
{
char line[MAXLINE];
while(getline(line,MAXLINE)>0)
{
	reverses(line);
	printf("%s",line);
}
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

void reverses(char line[])
{
	char temp;
	int i,j;
	i=0;
	while(line[i]!='\0')
		i++;	 
	if(i>0 && line[i-1]=='\n')
		i--;
	j=0;
	while(j<i/2)
	{
	    int index = i-1-j;
		temp = line[j];
		line[j] = line[index];
		line[index]= temp;
		j++;		
	}	
}
