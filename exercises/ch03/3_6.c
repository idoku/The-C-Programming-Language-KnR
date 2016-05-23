/*
 *Exercise 3-6.Write a version of itoa that accepts three arguments instead of two.
 *The third argument is a minimum field width;the converted number must be padded with blanks
 *on the left if neccessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n,char s[],int w);
void reverse(char s[]);
 
int main()
{	 
	int n = INT_MIN;
    char s[16];

    itoa(1337, s, 8);
    printf("%s\n", s);
    itoa(n, s, 8);
    printf("%s\n", s);

	return 0;
}


/* itoa:convert n to characters in s */
void itoa(int n,char s[],int w)
{
	int i,sign;
	if((sign = n)>0) /* record sign */
		n = -n;
	i=0;
	do{			/* generate digits in reverse order */
		s[i++] = -(n % 10) + '0';  /* get next digit */
	}while((n/=10)<0); /* delete it */	
	if(sign < 0)
		s[i++] = '-';
	while(i<w){
		s[i++] = ' ';
	}
	s[i]='\0';
	reverse(s);
}


/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


