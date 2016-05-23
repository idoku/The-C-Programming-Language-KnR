#include <stdio.h>

int atoi(char s[]);

int main()
{
	char s[] = "128";
	int n = atoi(s);
	printf("%d",n);
}
	  
	  
/* atoi:convert s to integer */
int atoi(char s[])
{
	int i,n;
	n=0;
	for(i=0;s[i]>='0' && s[i]<='9';++i)
		n = 10 * n +(s[i] - '0');
	return n;
}