/*
 *Exercise 4-12. Adapt the idea of printd to write a recursive version of itoa.
 *that is,convert an integer into a string by calling a recursive routine.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n,char s[]);

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
 	static int i,sign;
	if((sign = n)>0) /* record sign */
			n = -n;
	if(n/10)
	{
		if(sign>0){
			itoa(-n/10,s);
		}else{
			itoa(n/10,s);
		}
	}
	else{
		i=0;	
		if(sign < 0)
			s[i++] = '-';
	}
	s[i++] =  -(n % 10) + '0';  /* get next digit */
	s[i]='\0';
}
