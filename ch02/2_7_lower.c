#include <stdio.h>

int lower(int c);

int main()
{
	int i;
	for(i='A';i<='Z';i++)
		printf("%c ",lower(i));
	return 0;
}


/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if(c>='A' && c<='Z')
		return c+'a'-'A';
	else
		return c;
}