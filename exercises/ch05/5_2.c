/*
 *Exercise 5-2.Write getfloat,the floating-point analog of getint.
 *What type does getfloat return as its function value?
*/
 
 /*
	getfloat return integer,because it use *fp save float.
 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getfloat(float *fp);
int getch(void);
void ungetch(int);

int main(){
	int c;
	float f;
	while((c=getfloat(&f))!=EOF && c!=0)
	    printf("%f\n",f);
	if(c==0)
	   printf("error:input is not a number.");
	return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(float *fp)
{
	double power;
	int c,sign,sawsign;
	while(isspace(c=getch())) /* skip with space */
		;
	if(!isdigit(c) && c !=EOF && c!='+' && c!='-')
	{
		ungetch(c);
		return 0;
	}
	sign = ( c == '-' )?-1:1;
	if(c=='+' || c=='-'){
		c = getch();	
	    if(!isdigit(c)){
		ungetch(c);
		if(sawsign)
			ungetch((sign==-1)?'-':'+');
		return 0;
		}
	}	

	
	for(*fp = 0;isdigit(c);c=getch())
		*fp = 10 * *fp + (c - '0');
	
	if(c=='.'){	
		c = getch();
	}
	
	for(power=1.0;isdigit(c);c=getch())
	{
		*fp = 10.0 * *fp + (c-'0');
		power *=10.0;	    
	}

	*fp *= (sign / power);
	if(c!=EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

int buf[BUFSIZE]; /* buffer for ungetch */
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
