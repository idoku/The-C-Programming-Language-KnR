/*
 * Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. 
*/
#include <stdio.h>

#define MAXLINE 100

int main()
{
	char lines[MAXLINE];
	int i,c;
	for(i=0;i<MAXLINE-1;++i)
	{
		c = getchar();
		if(c==EOF)
		{
			break;
		}
		else if(c=='\n')
		{			 
			 lines[i++]='\0';
			 break;
		}
		lines[i]=c;
	}
	printf("%s",lines);
	return 0;
}

 