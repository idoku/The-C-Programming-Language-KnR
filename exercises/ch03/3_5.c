/*
 *Exercise 3-5.Write the function itob(n,s,b) that converts the integer n into a base b character
 *representation in the string s.In particular itob(n,s,16) formats n as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>

/*  itob: convert n to charecters in s - base b */
void itob(int n,char s[],int b);
char itoc(int n);

/* reverse: reverse string s in place */
void reverse(char s[]);

int main()
{
	int i,n;
	char s[25];
	n =255;
	int f[] = {2,8,10,16};
	for(i=0;i<4;i++)
	{
		itob(n,s,f[i]);
		printf("%s\r\n",s);
	}
	return 0;
}

/* itoc : convert n to character */
char itoc(int n)
{
	return n<10 ? (n+'0') : (n-10+'a');
}

/*  itob: convert n to charecters in s - base b */
void itob(int n,char s[],int b)
{
	int i,sign;	
	char c ;
	if((sign = n)>0) /* record sign */
		n = -n;
	i = 0;
	do{		
		c = itoc(-(n%b));			
		s[i++] = c;
	}while((n/=b)<0);
	if(sign<0)
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