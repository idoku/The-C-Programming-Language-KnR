#include <stdio.h>
/*
 *Exercise 5-5. Write versions of the library functions strncpy,strncat,and strncmp,
  which operate on at most the first n characters of their argument strings.
  For example,strncpy(s,t,n) copies at most n characters of t to s.Full descriptions are in Appendix B.
*/
void strncpy(char *s,char *t,int n);
void strncat(char *s,char *t,int n);
int strncmp(char *s,char *t,int n);

int main()
{
	char s[] = "abc";
	char t[] = "def";
	strncpy(s,t,2);
	printf("%s\n",s);	
	strcpy(s,"abc");
	strncat(s,t,2);
	printf("%s\n",s);	
	strcpy(s,"abc");
	strcpy(t,"abf");
	int i = strncmp(s,t,2);
	printf("%d",i);
}

//copy at most n characters of string ct to s;return s.
//pad with '\0's if ct has fewer than n characters.
void strncpy(char *s,char *t,int n)
{	
    while(*t && n-->0)
        *s++=*t++;		
	*s='\0';
}

//concatenate at most n characters of string t to string s
//terminate s with '\0';return s;
void strncat(char *s,char *t,int n){	
	while(*s) /* find end of s */
		*s++;
	while(*t && n-->0) /* copy t */
		*s++=*t++;	
	*s='\0';
}

//compare at most n characters of string s to string t; return <0
//if s<t,0 if s==t,or >0 if s>t
int strncmp(char *s,char *t,int n)
{
	for(;*s==*t && n-->0;s++,t++)
		if(*s=='\0' || n==0)
			return 0;
	return *s-*t;
}