#include <stdio.h>

int main()
{
	char s[] = " -125 ";
	int d = atoi(s);
	printf("%d\n",d);
	return 0;
}

/* atoi:convert s to integer;version 2 */
int atoi(char s[])
{
	int i,n,sign;
	for(i=0;isspace(s[i]);i++) /* skip white space */
		;
	sign = (s[i]=='-')?-1:1;
	if(s[i]=='+' || s[i]=='-') /* skip sign */
		i++;
	for(n=0;isdigit(s[i]);i++)
		n=10*n+(s[i]-'0');
	return sign * n;
}
