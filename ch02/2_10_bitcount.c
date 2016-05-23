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
    for(b=0;x!=0;x>>=1)
        if(x & 01)
           b++;
    return b;
}