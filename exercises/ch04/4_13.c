/*
 *Exercise 4-13. Write a recursive version of the function reverse(s),which reverses the string s in place.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[],int begin,int end);

int main()
{
	char s[] = "hello world.";
	reverse(s,0,strlen(s)-1);
	printf("%s",s);
	return 0;
}

 
/* reverse: reverse string s in place */
void reverse(char s[],int begin,int end)
{	
	char c;
	if(begin>=end)
		return;
	c = s[begin];
	s[begin] = s[end];
	s[end] = c;		
	reverse(s,++begin,--end);
}
