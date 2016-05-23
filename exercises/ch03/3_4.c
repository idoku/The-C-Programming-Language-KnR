/*
 *Exercise 3-4.In a two's complement number repressentation,our version of itoa does not handle
 *the largest negative number,that is,the value of n equalto -(2^(wordsize-1)).Explain why not.
 *Modify is to print that value correctly,regardless of the machine on which it runs.
*/

/*
* answer:because in two's complement number,highest bit is sign bit,-(2^(wordsize-1)) nageta error.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n,char s[]);
void reverse(char s[]);


int main()
{
	int min = INT_MIN;
	int max = INT_MAX;
	printf("int signed:min=%d,max=%d.\n",INT_MIN,INT_MAX);
	char s[50];	
	itoa(min,s);
    printf("%s\n",s);	
	itoa(max,s);
	printf("%s\n",s);	
	return 0;
}


/* itoa:convert n to characters in s */
void itoa(int n,char s[])
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


