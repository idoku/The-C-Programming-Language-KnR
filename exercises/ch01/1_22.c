/*
 *Exercise 1-22. Write a progarm to "fold" long input lines into 
 *two or more shorter lines after the last non-blank character that 
 *occurs before the n-th column of input.Make sure your program does 
 *something intelligent with very long lines,and if there are no blanks 
 *or tabs before the specified column,
*/

#include "stdio.h"

#define TABSIZE 4 /* Tab increment size */
#define LINELENGTH 10  

int main()
{
   char c;
   int i,pos,wslen,wordlen,linelen;
   char wordbuf[LINELENGTH];
   
   pos = wslen =  wordlen = linelen =0;   
   while((c=getchar())!=EOF)
   {
     if(c==' ' || c == '\t'){			
		wslen += (c == '\t' ? TABSIZE : 1);		
		if(linelen + wslen > LINELENGTH){
			putchar('\n');						
			linelen = wslen = 0;
		}
	 }	
	 else if(c=='\n'){			    	
		putchar(c);
		linelen = wslen = 0;
	 }
	 else{
	    if(wslen>0){
			if(linelen + wslen < LINELENGTH){
				for(i=0;i<wslen;i++)
					putchar(' ');					
			}
			else{
				putchar('\n');
				linelen=0;
			}
		
		}
		else if(linelen>LINELENGTH){
		   putchar('\n');
		   linelen=0;
		}
		wslen = 0;
		putchar(c);
	    linelen++;
	}		 
   }
   return 0;
}
