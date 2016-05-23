/*
 *Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly.
 *Decide what their properties ought to be if an EOF is pushed back,then implement your desgin.
*/

/*
answer:
We must declare c to be a type big enough to hold any value that getchar returns. 
We can't use char since c must be big enough to hold EOF in addition to any possible char. 
Therefore we use int.
*/

#include <stdio.h>

int getch(void);
void ungetch(int c);

int main()
{
	int c;
	while((c=getch())!=EOF)
		putchar(c);
	return 0;
}

#define BUFSIZE 100

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c) /* push character back on input */
{
	if(bufp>=BUFSIZE)
		printf("ungetch:too many characters\n");
	else
		buf[bufp++]=c;
}
