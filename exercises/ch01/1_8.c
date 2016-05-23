#include <stdio.h>
 
/* count in input */
int main()
{
    int c,n1,n2,n3;
    n1=0;
    n2=0;
    n3=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
            ++n1;
        else if(c=='\t')
            ++n2;
        else if(c==' ')
            ++n3;
     }
    printf("newline=%d\ntab=%d\nspace=%d\n",n1,n2,n3);
    return -1;
}