/*
 *Exercise 1-21. Write a program entab that replaces strings of blanks
 *by the minimum number of tabs and blanks to achieve the same spacing.
 *Use the same tab stops as for detab.When eithera tab or a single blank 
 *would suffice to reach a tab stop,which should be given preference? 
*/

#include <stdio.h>

#define TABSIZE 8 /* Tab increment size */

int main()
{
	int c,no_blank,no_tab,pos;
	no_blank=no_tab=0;
	pos=0;
	while((c=getchar())!=EOF)
	{
		if(c==' '){
			++pos;		
		}
		else if(c=='\n')
		{
			putchar(c);
			pos = 0 ;
		}
		else
		{
			if(pos>0){
				no_blank = pos%TABSIZE;
				no_tab = pos/TABSIZE;
				while(no_tab>0)
				{			 
					putchar('\t');			
					pos-=TABSIZE;
					--no_tab;
				}
				while(no_blank>0)
				{
					putchar(' ');
					--pos;
					--no_blank;
				}
			}
			putchar(c);        
		}
	}
	return 0;
}