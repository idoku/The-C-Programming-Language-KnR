/*
 *Exercise 4-7. Write a routine ungets(s) what will push back an entire string onto the input.
 *Should ungets know about buf and bufp,or should it just use ungetch?
*/

#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int main()
{
	char c;
	char s[] = "hello, world.";
	ungets(s);
	while ((c = getch()) != EOF)
		printf("%c",c);
	return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
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

void ungets(char s[]) /* push string back on input */
{
  int len = strlen(s);
  while(len>0)
    ungetch(s[--len]);
}

