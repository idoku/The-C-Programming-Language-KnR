#include <stdio.h>

#define MAXLINE 100

void squeeze(char s[],int c);
int getline(char line[],int maxline);
 

int main()
{
	char c = 'k';
	char line[MAXLINE];
	int len;
	len = getline(line,MAXLINE);	
	squeeze(line,c);
	printf("%s",line);
	return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[],int c)
{
	int i,j;
	for(i = j = 0;s[i] !='\0';i++)
	{
		if(s[i] != c)
			s[j++]=s[i];
	}
	s[j]='\0';
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
 