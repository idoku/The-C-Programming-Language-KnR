#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100


int getword(char *,int);
int getch(void);
void ungetch(int c);

		
/* count C keywords */
int main()
{	 
	int n;
	char word[MAXWORD];
	 
	while(getword(word,MAXWORD)!=EOF)
	{	 
		printf("%s\n",word);
	}	
	return 0;
}

void delspace(void)
{
	char state = 0;
	int c;
	while(state!=2)
	{
		c = getch();
		switch(state)
		{
			case 0:
				if(c=='/')
					state = 1;
				else if(!isspace(c)){
					state=2;
					ungetch(c);
					}
				break;
			case 1:
				if(c=='*')
					state =3;
				else{
					state=2;					
					ungetch(c);					
					ungetch('/');					
				}
				break;
			case 3:
				if(c=='*'){
					state = 4;
				}
				break;
			case 4:
				if(c=='*' || c=='/'){
					if(c=='/')
						state =0;
				}else{
					state = 3;
				}
				break;
		}
	}
}

/* getwod: get next word or character from inpt */
int getword(char *word,int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word,scaped;
	//del space and comment
	delspace();		 
	
	c = *w++ = getch();
		
	if(!isalpha(c) && c!='_' && c!='#' && c!='"')
	{
		*w='\0';
		return c;
	}
	if(c='"'){
		for(;w<word+lim&&(isalnum(*w=c=getch())||c=='_');w++)
			;
		*w = '\0';
		ungetch(c);
		return word[0];
	}
	w--;
	while(w<word+lim-1){
		if((*w++=c = getch())=='"'&&!scaped)
			break;
		scaped = 0;
		if(c=='\\'){
			scaped=1;
			w--;
		}
	}		 
	*--w='\0';
	return word[0];
}



#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;

int getch(void)     /* get a(possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] =c;
}