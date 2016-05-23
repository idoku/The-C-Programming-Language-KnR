#include <stdio.h>

#define ALLOCSIZE 1000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* size of available space */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n);
void afree(char *p);

int main()
{
	char *p;
	p = alloc(1001);			
	printf("%s",p);
    afree(p);
    p = alloc(10);
	printf("%s",p);
}

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
	{
		allocp += n;
		return allocp - n; /* old p */
	}
	else /* not enough room */
	{
		return 0;
	}
}

void afree(char *p) /* free storage pointed to by p */
{
	if(p>=allocbuf&& p<allocbuf+ALLOCSIZE)
		allocp = p;
}