/*
Exercise 7-3. Revise minprintf to handle more of the other 
facilities of printf.
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void minprintf(char *fmt,...);

int main()
{
	minprintf("hello,%corld.",'w');
	return 0;
}


/* minprintf:minial printf with variable argument list */
void minprintf(char *fmt,...)
{
	va_list ap;/* points to each unnamed arg in turn */
	char *p,*sval;
	int ival;
	unsigned uval;
	double dval;
	
	va_start(ap,fmt); /* make ap point to 1st unnamed arg */
	for(p = fmt;*p;p++)
	{
		if(*p!='%'){
			putchar(*p);
			continue;
		}	
		
		switch(*++p)
		{
			case 'd':
			case 'i':
				ival = va_arg(ap,int);
				printf("%d",ival);
				break;
			case 'c':
				ival = va_arg(ap,int);
				putchar(ival);
				break;
			case 'u':
				uval = va_arg(ap,unsigned int);
				printf("%u",uval);
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for(sval=va_arg(ap,char *);*sval;sval++)
				{
					putchar(*sval);
				}
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); /* clean up when done */
}