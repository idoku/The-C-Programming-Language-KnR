/*
 * Exercise 2-1. Write a program to determine the ranges of char,short,int,and long
 * variables,both signed and unsigned,by printing appropriate values from standard headers 
 * and by direct computation.Harder if you compute them:determine the ranges of the various
 * floating-point types.
*/

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Direct Print Type Size\n");
	printf("Range of Char %d\n",CHAR_BIT);
	printf("char signed:min=%d,max=%d.\n",SCHAR_MIN,SCHAR_MAX);
	printf("char unsigned:min=%d,max=%d.\n",0,UCHAR_MAX);
	printf("short signed:min=%d,max=%d.\n",SHRT_MIN,SHRT_MAX);
	printf("short unsigned:min=%d,max=%d.\n",0,USHRT_MAX);
	printf("int signed:min=%d,max=%d.\n",INT_MIN,INT_MAX);
	printf("int unsigned:min=%d,max=%u.\n",0,UINT_MAX);
	printf("long signed:min=%ld,max=%ld.\n",LONG_MIN,LONG_MAX);
	printf("long unsigned:min=%d,max=%lu.\n",0,ULONG_MAX);
	
	printf("Cal Print Type Size\n");
	unsigned int i = ~0; 
    printf("Unsigned int max: %u\n", i); 
    printf("Signed int max: %d\n", i / 2); 
    printf("Signed int min: %d\n",  - (i / 2) - 1); 

	return 0;
}