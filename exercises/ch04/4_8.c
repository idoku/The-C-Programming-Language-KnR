/*
 *Exercise 4-8. Suppose that there will never be more than one character of pushback.
 *Modify getch and ungetch accordingly.
*/
 
#include <stdio.h>

int getch(void);
void ungetch(int c);

int main()
{
	int c;
	ungetch('!');
	while((c=getch())!=EOF)
		printf("%c",c);
	return 0;
}

char buf=0; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed back) character */
{
	int c;
	c = buf?buf:getchar();
	buf =0;
	return c;
}

void ungetch(int c) /* push character back on input */
{		
	if(buf)
		printf("ungetch:too many characters\n");
	else
		buf = c;	
}

