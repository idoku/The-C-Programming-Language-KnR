#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
	int c,state;
	state = OUT;
	while((c=getchar())!=EOF)
	{				
		if(c==' ' || c=='\t'){
			putchar('\n');
			state = OUT;
		}
	    else if(state == OUT){
			state = IN;			
			}	
        if(state==IN)
		  putchar(c);			
	 }	 	 
	return -1;
}