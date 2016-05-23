#include <stdio.h>

#define MAXLINE 100

void strcat(char s[],char t[]);
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
			strcat(s2,s1);			
			printf("%s",s2);
			cnt = 0;
		}
	}
	return 0;
}

/* stract: concatenate t to end of s;s must be big enough */
void strcat(char s[],char t[])
{
	int i, j;
	i = j = 0;
	while(s[i]!='\0') /* find end of s */
		i++;
	while((s[i++] = t[j++]) != '\0') /* copy t */
		;
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