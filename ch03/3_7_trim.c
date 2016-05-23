#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main()
{
	char s[] = "hello world.	 ";
	trim(s);
	printf("%s\n",s);
	return 0;
}

/* trim: remove traliling blanks,tabs,newlines */
int trim(char s[])
{
	int n = strlen(s)-1;	 
	for(;n>=0;n--)
	{		 
		 if(s[n]!=' ' && s[n]!= '\t' && s[n]!='\n')
			 break;			
	}
	s[n+1] = '\0';
	return n;
}