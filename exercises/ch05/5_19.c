#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXPOINTERS 10
enum { NAME,PARENS,BRACKETS } ;
enum { NO,YES};

int getch(void) ;
void ungetch(int c);
int nexttoken(void);
int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char out[1000]; /* output string */


int main() /* convert declaration to words */
{
	int type;
	int i,c;
	char temp[MAXTOKEN];	
	int pcount;
	char p[MAXPOINTERS];/* space for 9 pointers */
	while(gettoken()!=EOF){
		 strcpy(out,token);
		 pcount=0;
		 while((type=gettoken())!='\n'){
			 if(type==PARENS||type==BRACKETS)
				 strcat(out,token);
			 else if(type=='*'){
				 pcount++;
				 while((c=getch())=='*' || c==' '){
					if(c=='*'){
						if(pcount<(MAXPOINTERS-1))
							pcount++;
						else
							break;
					}					
				 }
				 ungetch(c);
				 for(i=0;i<pcount;i++)
					p[i]='*';
				 p[i]='\0';
				 pcount=0;
				sprintf(temp,"(%s%s)",p,out);				
				 strcpy(out,temp);
			 }else if(type==NAME){
				 sprintf(temp,"%s%s",token,out);
				 strcpy(out,temp);
			 }else
				 printf("invalid iput at %s\n",token);
		 }
	      printf("%s\n",out);
	}
	return 0;
}

#include <string.h>
#include <ctype.h>

extern int tokentype;   /* type of last token */
extern char token[];    /* last token string */
int prevtoken = NO; /* there is no previous token */

int gettoken(void) /* return next token */
{
	int c;   
    char *p = token;     
    while((c=getch()) == ' ' || c == '\t')
        ;

    if(c == '(')
    {
        if((c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for(*p++ = c; ( *p++ = getch()) != ']';)
            ;
        *p ='\0';
        return tokentype = BRACKETS;
    } 
    else if (isalpha(c))
    {
        for(*p++ = c; isalnum(c=getch()); )
            *p++ = c;        
        *p = '\0';        
        ungetch(c);
        return tokentype = NAME;
    }
    else{
        return tokentype = c;
	}
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