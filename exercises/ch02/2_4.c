/*
 *Exercise 2-4. Write an alternate version of squeeze(s1,s2) 
 *that deletes each character in s1 that matches any character in the string s2. 
*/

#include <stdio.h>

#define MAXLINE 100

void squeezes(char s1[],char s2[]);
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
			squeezes(s2,s1);			
			printf("%s",s2);
			cnt = 0;
		}
	}
	return 0;
}

/* squeeze: delete all s2 from s1 */
void squeezes(char s1[],char s2[])
{
	int i,j,k;
	for(i = 0;s2[i]!='\0';i++)
	{		 
		 for(k = j =0;s1[j]!='\0';j++)
		 {
				if(s1[j] != s2[i])
					s1[k++] = s1[j];
		 }
		 s1[k]='\0';
	}	
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
