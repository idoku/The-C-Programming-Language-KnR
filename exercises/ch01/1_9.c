#include <stdio.h>
 
int main()
{
    int c,nc;
    nc=0;
    while((c=getchar())!=EOF)
    {   
        if(c==' ')
          nc++;
        else
          nc=0;
        if(nc<2)
          putchar(c);
    }
    return -1;
}