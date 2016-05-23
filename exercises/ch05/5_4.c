#include <stdio.h>
#include <string.h>
/*
 *Exercise 5-4. Write the function strend(s,t),which returns 1 
  if the string t occurs at the end of the string s,and zero otherwise.
*/

int strend(char *s,char *t);

int main()
{
	char s[] = "abcdefg";
	char t[] = "abc";	
  	int n = strend(s,t);
	printf("%d\n",n);
}

/* strend:t coours at the end of s */
int strend(char *s,char *t){	
          int ls = strlen(s);
	  int lt = strlen(t);
	  if(ls>=lt){
		s += ls - lt;
		while(*s++==*t++)
		   if(!*s)
			return 1;
	 }	 
	 return 0;
}
