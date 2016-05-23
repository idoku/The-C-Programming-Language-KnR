/*
 *Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits 
 *that begin at position p set to the rightmost n bits of y,leaving the other bits unchanged. 
*/

#include <stdio.h>


unsigned setbits(unsigned x,int p,int n,unsigned y);

int main()
{
	int x = 128;
    int y = 127;
	int n = 3;
	int p = 4;
	int z = setbits(x,p,n,y);
	printf("%d",z);
	return 0;
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
	unsigned mask = ~(~0<<n);	
	return (x & ~(mask<<p+1-n)) | ((y & mask)<<p+1-n);
}