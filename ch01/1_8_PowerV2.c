#include <stdio.h>
 
int powerV2(int m, int n);

/* test power function */
int main()
{
    int i;
    for(i = 0;i < 10;++i )
    {
        printf("%d %d %d\n", i, powerV2(2,i),powerV2(-3,i));
    }
    return -1;
} 
 
/* power: raise base to n-th power; n >= 0 ; version 2*/
int powerV2(int base,int n)
{
    int p;
    for(p = 1; n > 0; --n)
        p = p * base;
    return p;
}