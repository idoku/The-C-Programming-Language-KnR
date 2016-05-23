#include <stdio.h>

int strcmp(char *s,char *t);

int main()
{	
    int i;
	char s[]="abc";
    char t[]="abc";
	i = strcmp(s,t);
	printf("%d\n",i);
	t[2]='b';
	i = strcmp(s,t);
	printf("%d\n",i);
	t[2]='d';
	i = strcmp(s,t);
	printf("%d\n",i);
}

/* strcmp: return <0 if s<t, 0 if s==t,>0 if s>t */
int strcmp(char *s,char *t)
{
	for(;*s==*t;s++,t++)
		if(*s=='\0')
			return 0;
	return *s-*t;
}