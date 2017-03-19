/*
Exercise 7-2. Write a program that will print arbitrary input in a sensible way.
As a minimum,it shoud print non-graphic characters in octal or hexadecimal 
according to local custom,and break long text lines.
*/

#include <stdio.h>

char form[] = "0x%x";
int wrapcol = 10;

void parseop(int argc,char *argv[])
{
	int c;
	while(--argc>0){		 
		if((*++argv)[0]=='-'){			
			while((c=*++argv[0])){				
				switch(c){
					case 'o':
						sprintf(form,"0%%%c",c);						
						break;
					case 'x':					
						sprintf(form,"0x%%%c",c);
						break;					
					default:
						printf("error");
						break;
				}
			
			}
		
		}
	
	
	}
}

int main(int argc,char *argv[])
{
	int col,c;
	parseop(argc,argv);
	col =0;
	while((c=getchar())!=EOF)
	{
		if(isdigit(c) || ispunct(c)){			  
			putchar(c);
		}else if(isspace(c)){			
			col = (c=='\n') ? 0: col;
			putchar(c);
		}
		else{		  
		  printf(form,c);
		}
		
		if(col>=wrapcol){
			printf("\n");
			col =0;
		}
		
		col++;
	}
	return 0;
}