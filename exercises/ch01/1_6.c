#include <stdio.h>
 
int main()
{
    int c;
    c = getchar()!=EOF;
    printf("%d\n",c);
    c = getchar()==EOF;
    printf("%d\n",c);
    return 0;
}