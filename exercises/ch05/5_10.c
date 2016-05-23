/*
 * Exercise 5-10. Write the program expr,which evaluates a reverse Polish expression from the command line,
 * where each operator or operand is a separate argument.For example,
 *   expr 2 3 4 + *
 *    evaluates 2 * (3 + 4).
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char *s);
void push(double);
double pop(void);
double top(void);


/* reverse Polish calculator */
int main(int argc,char *argv[])
{
	int c;
	double op2;
	char s[MAXOP];
	
	while(--argc>0){	    
		switch(c=getop(*++argv))
		{
			case NUMBER:
				push(atof(*argv));
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
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error:unknown command %s \n",s);
				break;
		}
		printf("%g",top());
	}
	
	printf("=%g\n",pop());
	return 0;
}

int getop(char *s)
{
	if(!isdigit(s[0]) && s[1]=='\0'){
		return s[0];
	}
	return NUMBER;
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

double top(void)
{
    	if(sp>0){
    	    return val[sp];
    	}
    return 0.0;
}

