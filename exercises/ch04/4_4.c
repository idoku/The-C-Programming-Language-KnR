/*
 *Exercise 4-4. Add commands to print the top element of the stack without popping,
 *do duplicate it,and to swap the top two elements.Add a command to clear the stack.
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
 
void push(double);
double pop(void);
double top(void);
void duplicate(void);
void swap(void);
void clear(void);

 
/* reverse Polish calculator */
int main()
{
	double tmp ;
	push(1.1);
	push(2.1);
	push(3.1);
	push(4.1);
	tmp = top();
	printf("%.8g\n",tmp);
	tmp = pop();
	printf("%.8g\n",tmp);
	duplicate();
	tmp = pop();
	printf("%.8g\n",tmp);
	tmp = pop();
	printf("%.8g\n",tmp);
	swap();	
	tmp = top();
	printf("%.8g\n",tmp);
	clear();
	top();
	return 0;
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

/* top: return top value from stack without popping */
double top(void)
{
	if(sp>0)
		return val[sp-1];
	else{
		printf("error:stack empty\n");
		return 0.0;
	}
}

/* duplicate: duplicate top value and push stack */
void duplicate(void)
{
	 double tmp = top();
	 push(tmp);
}

/* swap: swap the top two elements */
void swap(void)
{
	double tmp1 = pop();
	double tmp2 = pop();
	push(tmp1);
	push(tmp2);
}

/* clear: clear stack */
void clear(void)
{
	sp = 0;
}
