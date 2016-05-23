#include <stdio.h>

int strlen(char *s);

int main()
{

	int len;
	len = strlen("hello,world");	
	printf("%d\n",len);
	char array[10];
	len = strlen(array);
	printf("%d\n",len);
	char *ptr;
	len = strlen(ptr);
	printf("%d\n",len);
	return 0;
}


/* strlen:return length of string s */
int strlen(char *s)
{
	char *p = s;
	while(*p!='\0')
		p++;
	return p-s;
}