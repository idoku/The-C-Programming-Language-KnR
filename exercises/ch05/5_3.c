#include <stdio.h>
/*
 *Exercise 5-3. Write a pointer version of the function strcat that we showed in 
  Chapter 2:strcat(s,t) copies the string t to the end of s.
*/

void strcat(char *s,char *t);

int main()
{
	char s[] = "abc";
	char t[] = "def";
	strcat(s,t);
	printf("%s",s);
}

/* stract: concatenate t to end of s;s must be big enough */
void strcat(char *s,char *t){	
	while(*s) /* find end of s */
		*s++;
	while(*s++=*t++) /* copy t */
		;	
}
