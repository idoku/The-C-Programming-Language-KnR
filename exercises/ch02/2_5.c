/*
 *Exercise 2-5. Write the function any(s1,s2),which returns the first location in the string 
 *s1 where any character from the string s2 occurs,or -1 if s1 contains no characters from s2.
 *(The standard library function strpbrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

#define MAXLINE 100

int any(char s1[],char s2[]);
int getline(char line[],int maxline);
void copy(char to[],char from[]);

int main()
{
	char s1[MAXLINE],s2[MAXLINE];
	int len,cnt = 0;
	while((len = getline(s1,MAXLINE)) > 0){
		if(cnt== 0){
			copy(s2,s1);			
			cnt =1;
		}else{
			int i = any(s2,s1);			
			printf("s1:%s,s2:%s,index:%d",s1,s2,i);
			cnt = 0;
		}
	}
	return 0;
}

int any(char s1[],char s2[])
{
	int i,j,k;
	for(i = 0;s1[i]!='\0';i++)
	{		 
		 for(j =0;s2[j]!='\0';j++)
		 {
				if(s1[i] == s2[j])
					return i;
		 }		 
	}	
	return -1;
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
 
 /* copy: copy 'from' into 'to';assume to is big enough */
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
