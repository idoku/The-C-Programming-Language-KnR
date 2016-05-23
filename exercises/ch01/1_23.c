/*
 *Exercise 1-23. Write a program to remove all comments
 *from a C program.Don't forget to handle quoted strings and 
 *character constants properly.C comments do no nest. 
*/

#include "stdio.h"

#define MAXLINE 1000

char line[MAXLINE];

int main()
{
	char c,prevc,nextc;
	while((c=getchar())!=EOF)
	{
		if(c=='"'){
			putchar(prevc=c);
			while((c=getchar())!='"' || prevc=='\\')
				putchar(prevc=c);
			putchar(prevc= c);
		}
		else if(c=='/'){
			nextc = getchar();
			if(nextc=='/'){
				while((c=getchar())!='\n')
					;
				putchar('\n');
			}else if(nextc=='*'){
				//putchar(nextc);
				prevc = getchar();
				while((c=getchar())!='/' || prevc!='*'){
					prevc = c;
				}
			}else{
				putchar(c);
				putchar(prevc=nextc);
			}
		}
		else{
			putchar(prevc=c);
		}			
	}
	return 0;
}
