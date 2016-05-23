/*
 *Exercise 2-9. In a two's comppement number system,x &= (x-1) 
 *deletes the rightmost 1-bit in x.Explain why.Use this observation 
 *to write a faster version of bitcount.
*/

/*
 * because x-1 set x rightmost 1 to zero.
*/

#include <stdio.h>

int main()
{
	int cnt = bitcount(15);
	printf("%d",cnt);
}

/* bitcount: count 1 bit in x */
int bitcount(unsigned x)
{
    int b;
    for(b=0;x!=0;x&=(x-1))      
           b++;
    return b;
}