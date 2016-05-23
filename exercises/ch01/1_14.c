/*
 *	Exercise 1-14. Write a program to print a histogram 
 *    of the frequencies of different characters in its input.
*/

#include <stdio.h>

 
int main()
{
	int c,i;
	int ncharacter[52];	 
	for(i=0;i<52;++i)
		ncharacter[i] = 0;
	while((c=getchar())!=EOF)	
		 if(c>='a' && c <= 'z' )
		    ++ncharacter[c-'A'-6];//other 6 characters
		 else if(c>='A' && c<='Z')
			  ++ncharacter[c-'A'];		 
	for(i=0;i<52;i++)
	{
		c = i + 'A';
		if(c >'Z')
			c += 6 ;
		printf("%c",c);
	}
	int state = 1;
	while(state)
	{
		printf("\n");
		state = 0;
		for(i=0;i<52;i++)
		{
			if(ncharacter[i]>0)
			{
				--ncharacter[i];
				printf("*");
				state = 1;
			}
			else
			{
				printf(" ");
			}
			
		}
	}
	return -1;
}