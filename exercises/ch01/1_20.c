/*
 *Exercise 1-20. Write a program detab that replaces tabs
 *in the input with the proper number of blanks to spae to 
 *the next tab stop.Assume a fixed set of tab stops,say every
 *n columns.Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TABSIZE 8 /* Tab increment size */

int main()
{
	int c,no_blanks,pos;
	no_blanks = 0 ; /* number of blamks required */
	pos = 1; /* postition of the character */
	while((c=getchar())!=EOF){
		if(c=='\t'){
			no_blanks = TABSIZE - (pos - 1)%TABSIZE;
		while(no_blanks>0){
			putchar(' ');
			++pos;
			--no_blanks;
		}
		}
		else if(c=='\n'){
			putchar(c);
			pos=1;
		}
		else{
		putchar(c);
		++pos;
		}
	}
	return 0;
}

/*
A tab character should advance to the next tab stop. Historically tab stops were every 8th character.
                                0       8       16      24      32      40
                                |.......|.......|.......|.......|.......|
printf("\tbar\n");              \t      bar
printf("foo\tbar\n");           foo\t   bar
printf("longerfoo\tbar");       longerfoo\t     bar
refrence:http://stackoverflow.com/questions/13094690/how-many-spaces-for-tab-character-t
*/