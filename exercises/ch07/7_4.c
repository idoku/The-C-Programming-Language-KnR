/*
	Exercise 7-4. Write a private version of scanf 
	analogous to minprintf from the previous section.
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int minscanf(char *fmt,...);

int main()
{
    int day,month,year;	
	minscanf("%d %d %d",&day,&month,&year);
	printf("%d-%d-%d",day,month,year);
	return 0;
}


int minscanf(char *fmt,...){
	va_list ap;/* points to each unnamed arg in turn */
	char *p,*sval;
	int *ival;
	unsigned *uval;
	double *dval;
	
	va_start(ap,fmt); /* make ap point to 1st unnamed arg */

	for(p = fmt;*p;p++)
	{
		if(*p!='%'){		
			continue;
		}
		switch(*++p)
		{
			case 'd':
			case 'i':
				ival = va_arg(ap,int *);				
				scanf("%d",ival);
				break;
			case 'c':
				ival = va_arg(ap,int *);
				scanf("%c",ival);
				break;
			case 'u':
				uval = va_arg(ap,unsigned int *);
				scanf("%u",uval);
			case 'f':
				dval = va_arg(ap,double *);
				scanf("%f",dval);
				break;			
			default:							
				break;
		}

	}
	va_end(ap); /* clean up when done */
	return -1;
}

