#include <stdio.h>

void strcpy(char *s,char *t);

int main()
{	
	char s[]="abc";
    char t[]="def";
	strcpy(s,t);
	printf("%s",s);
}

void strcpy(char *s,char *t)
{
    while(*s++=*t++)
        ;
}