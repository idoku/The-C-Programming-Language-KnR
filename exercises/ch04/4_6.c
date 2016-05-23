/*
 *Exercise 4-6.Add commands for handling variables.(it's easy to provide twenty-six variables 
 *with single-letter names.) Add a variable for the most recently printed value.
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNC   '1' /* signal that func was found  */
#define ALPHA    '2' /* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);
void dofunc(char s[]);
int chartoi(char z);

/* reverse Polish calculator */
int main()
{
	int type,i,val;
	double op2;
	char s[MAXOP];
	double var[26];
	for(i = 0; i < 26; i++)
        var[i] = 0.0;
	while((type=getop(s))!=EOF)
	{
	//sin,exp,and pow
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case FUNC:
				dofunc(s);
				break;
			case ALPHA:
				val = chartoi(s[0]);				
				if(var[val]!=0)
					push(var[val]);
				else
					push(s[0]);
				printf("%d,%g,%c\n",val,var[val],s[0]);
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
			case '=':
				  val = chartoi(pop());
				  var[val] = pop();
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


int chartoi(char z)
{
   z = toupper(z);
   if( z >= 'A' && z <= 'Z')
      return z - 'A';
   return 0;
}


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
		if(i==1)
			return ALPHA;
		else
			return FUNC;	
	}
	if(!isdigit(c) && c!='.' && c!='-')
	{			
		return c; /* not a number */	
	}
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