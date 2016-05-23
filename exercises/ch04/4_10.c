/*
 *Exercise 4-10.An alternate organization uses getline to read an entire input line;
 *this makes getch and ungetch unnecessary.Revise the calculator to use this approach.
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXLINE 1000   /* maximum input line length */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNC   '1' /* signal that func was found  */

int getop(char []);
void push(double);
double pop(void);
int getline(char s[],int lim);
void dofunc(char s[]);

char line[MAXLINE];
int  lp=0;
/* reverse Polish calculator */
int main()
{	
	int type;
	double op2;
	char s[MAXLINE];
	getline(line,MAXLINE);
	 
	while((type=getop(s))!='\0')
	{	
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case FUNC:
				dofunc(s);
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2 = pop();
				push(pop()-op2);
				break;
			case '/':
				op2 = pop();
				if(op2!=0.0)
					push(pop()/op2);
				else
					printf("error:zero divisor\n");
					break;
			case '%':
				op2 = pop();
				if(op2 !=0.0)				
				 push(fmod(pop(),op2));
				else
				  printf("error: zero devisor\n");
				break;			
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error:unknown command %s \n",s);
				break;
		}
	}
	return 0;
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

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next freee stack opsition */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++] = f;
	else
	    printf("error:stack full,can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if(sp>0)
		return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}

/* getop: get next operator or numeric opperand */
int getop(char s[])
{
	int i,c;		
	while((s[0]=c=line[lp++])==' '||c=='\t')
		;	
	s[1]='\0';
	i=0;
	if(isalpha(c)){
		while(isalpha(s[++i]=c=line[lp++]))
			;
		s[i] = '\0';	 
		return FUNC;	
	}
	if(!isdigit(c) && c!='.' && c!='-')	
		return c; /* not a number */	
	if(isdigit(c) || c=='-') /* collect integer part */
		while(isdigit(s[++i]=c=line[lp++]))
			;
	if(c=='.') /* collect fraction part */
		while(isdigit(s[++i]=c=line[lp++]))
			;
	s[i]='\0';		 
	lp--;
	return NUMBER;				
}

/* getline: get line into s,return length */
int getline(char s[],int lim)
{
	int c,i;
	i = 0;
	while(--lim>0&& (c=getchar())!=EOF && c!='\n')
		s[i++] = c;
	if(c=='\n')
		s[i++] = c;
	s[i]='\0';
	return i;
}
