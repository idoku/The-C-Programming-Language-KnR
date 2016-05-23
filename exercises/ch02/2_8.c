/*
 *Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x 
 *rotated to the right by n bit positions.
*/
#include <stdio.h>

unsigned rightrot(unsigned x,unsigned n);
 
int main()
{
	int y = rightrot(3,1);
	printf("%u",y);
	return 0;
}

/*rightrot:  rotates x to the right by n bit positions */
unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) {
        if(x & 1)   /* rightmost bit of x is 1 */
            x = (x >> 1) | ~(~0U >> 1);
        else        /* rightmost bit of x is 0 */
            x = x >> 1;
        --n;
    }
    return x;
}

 