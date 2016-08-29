#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
	int (*func)(int);
	int c;
	if(argc>1)
		++argv;
	if(!strcmp(*argv,"tolower"))
		func = tolower;
	else if(!strcmp(*argv,"toupper"))
		func = toupper;
	else
	{
		printf("error");
		return 1;
	}
	while((c=getchar())!=EOF)
	{	
			putchar(func(c));
	}
	return 0;
}

