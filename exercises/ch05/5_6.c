/*
 *Exercise 5-6.Rewrite appropriate programs from earlier chapters and exercises 
 *with pointers instead of array indexing.Good possibilities incllude getline(Chapters 1 and 4),
 *atoi,itoa,and their variants(Chapters 2,3,and 4),reverse(Chapter 3),and strindex and getop(Chapter 4).
*/
#include <stdio.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getline(char *s,int lim);
int atoi(char *s); 
void itoa(int n,char *s);
void reverse(char *s);
int strindex(char *s,char *t);
int getop(char *s);
int getch(void);
void ungetch(int c);

int main()
{
    // char line[1000];
	// while(getline(line,1000)>0){
		// printf("%s",line);
	// }
	
	// char s[] = "128";
	// int n = atoi(s);
	// printf("%d",n);
	
	// char s[50];
	// int n = 1024;
	// itoa(n,s);
    // printf("%s",s);
	
	//char s[] = "hello,world.";
	//char t[] = "rld";
	//int n = strindex(s,t);
	//printf("%d",n);
	
	 int type;
	 char s[MAXOP];
	 while((type=getop(s))!=EOF){
		printf("s=%s\n",s);
	 }
	
	return 0;
}

/* getop: get next operator or numeric opperand */
int getop(char *s)
{
	int i,c;
	while((*s=c=getch())==' '||c=='\t')
		;
	*++s='\0';
	if(!isdigit(c) && c!='.')
		return c; /* not a number */
	--s; //remove the \0
	if(isdigit(c)) /* collect integer part */
		while(isdigit(*++s=c=getch()))
			;
	if(c=='.') /* collect fraction part */
		while(isdigit(*++s=c=getch()))
			;
	*s='\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;				
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c) /* push character back on input */
{
	if(bufp>=BUFSIZE)
		printf("ungetch:too many characters\n");
	else
		buf[bufp++]=c;
}

/* strindex: return index of t in s,-1 if none */
int strindex(char *s,char *t)
{
	char  *i,*j,*k;
	for(i=s;*i!='\0';i++){	    
		j = i,k = t;
		while(*k!='\0' && *j++==*k++)
			;
		if(k-t>0 && *k == '\0'){
			return i-s;
		}
	}
	return -1;
}

/* itoa:convert n to characters in s */
void itoa(int n,char *s)
{
	int i,sign;
	char *p;
	p = s;
	if((sign = n)<0) /* record sign */
		n = -n;		/* make n positive */
	i=0;
	do{			/* generate digits in reverse order */
		*p++ = n % 10 + '0';  /* get next digit */
	}while(n/=10); /* delete it */
	if(sign < 0)
		*p++ = '-';
	*p='\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
	char tmp,*p;
	p = s+ strlen(s)-1;
	while(p>s){
		tmp = *s;
		*s++ = *p;
		*p-- = tmp;
	}
	
}

/* atoi:convert s to integer */
int atoi(char *s)
{
	int n,sign;	
	while(isspace(*s))
		;
	sign = *s == '-'?-1:1;
       if(*s=='+'||*s=='-')
		*s++;
	for(n=0;isdigit(*s);*s++)
		n = 10 * n +(*s - '0');
	return sign*n;
}

/* getline: get line into s,return length */
int getline(char *s,int lim)
{
	char c,*p;
    p = s;	
	while(--lim>0&& (c=getchar())!=EOF && c!='\n')
		*s++ = c;
	if(c=='\n')
		*s++ = c;
	*s='\0';
	return s-p;
}
