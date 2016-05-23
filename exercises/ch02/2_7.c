/*
 *Exercise 2-7. Write function invert(x,p,n) that returns x with the n bits 
 *that begin at position p inverted(i.e.,1 changed into 0 and vice versa),
 *leaving the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned x,unsigned p,unsigned n);

int main()
{	
	unsigned x = 170;
	int p = 5;
	int n = 4;
	int y = invert(x,p,n);
	printf("%u",y);
	return 0;
}

unsigned invert(unsigned x,unsigned p,unsigned n)
{
	unsigned mask = (~(~0<<n)) << (p-n+1);		
	return mask ^ x;
}

 