#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define ERROR '7'

int getop(void);
void push(double);
double pop(void);
 
 char line[MAXOP];
 char *ptr = NULL;
double dec_opt;
char c_opt;
 
 char *refill(void){  
	return fgets(line,MAXOP,stdin);
 }
 
 
/* reverse Polish calculator */
main()
{	 
	int type;
	double op2;
	char s[MAXOP];
	while((type=getop())!=EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(dec_opt);
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
	}
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

/* getop: get next operator or numeric opperand */
int getop(void)
{	 
	 double dval;
	 char cval;
	 char sval[MAXOP];
	 
	 if(ptr==NULL){
	     if(refill()==NULL)
			return EOF;
		ptr = line;
	 }
	
  while (*ptr == ' ' || *ptr == '\t' || *ptr == '\0') {
	if (*ptr == '\0') {
	    if (refill() == NULL)
		return EOF;
	    ptr = line;
	} else
	    ptr++;
    }
		
	if ((sscanf (ptr, "%lf", &dval)) == 1) {
	while (isdigit(*ptr))
	    ptr++;
	if (*ptr == '.') {
	    ptr++;
	    while (isdigit(*ptr))
		ptr++;
	}
	dec_opt = dval;
	return NUMBER;
    }
	
	sscanf(ptr,"%c",&cval);
	 if (cval == '+' ||  cval == '-' || cval == '*' || 
	 cval == '/' || cval == '%' || cval == '\n') {
		ptr++;
	return cval;
    }else
		return ERROR;		
}
 