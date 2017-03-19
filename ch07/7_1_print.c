#include <stdio.h>

int main()
{
	char *s = "hello,world";
	printf("%s:\n",s);
	printf("%10s:\n",s);
	printf("%.10s:\n",s);
	printf("%-10s:\n",s);
	printf("%.15s:\n",s);
	printf("%-15s:\n",s);
	printf("%-15.10s:\n",s);
	return 0;
}