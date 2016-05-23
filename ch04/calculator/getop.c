#include <stdio.h>
#include <ctype.h>
#include "calc.h"


/* getop: get next operator or numeric opperand */
int getop(char s[])
{
	int i,c,sign;
	while((s[0]=c=getch())==' '||c=='\t')
		;
	s[1]='\0';
	i=0;	 
	if(isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c!=EOF)
			ungetch(c);			
		return FUNC;	
	}
	if(!isdigit(c) && c!='.' && c!='-')
		return c; /* not a number */	
	if(isdigit(c) || c=='-') /* collect integer part */
		while(isdigit(s[++i]=c=getch()))
			;
	if(c=='.') /* collect fraction part */
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;				
}

/* sin,exp,and pow.*/
void dofunc(char s[])
{
	double op1,op2;
	if(strcmp(s,"sin")==0)
		push(sin(pop()));
	else if(strcmp(s,"exp")==0)
		push(exp(pop()));
	else if(strcmp(s,"pow")==0){
		op1 = pop();
		op2 = pop();
		if (op1 == 0 && op2 <= 0) 
              printf("error: domain (%g^%g)\n", op1, op2); 
        else 
            push(pow(op1, op2)); 
	}
	else{
		printf("error: unknown command %s\n", s);
	}
}
