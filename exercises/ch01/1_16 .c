/* 
 * Exercise 1-16. Revise the main routine of the longest-line
 * program so it will correctly print the length of arbitrarily 
 * long input lines,and as much as possible of the text.

*/
#include<stdio.h>

#define MAXLINE 5

int getline(char line[],int maxline);
void copy(char to[],char from[]);

int main()
{
    char line[MAXLINE];
	char longest[MAXLINE];
	char temp[MAXLINE];
	int len,max,prevmax,getmore;
	max = prevmax = getmore = 0;
	while((len = getline(line,MAXLINE)) > 0){
	   if(prevmax+ len > max){
			max = prevmax + len;
			if(!prevmax)
				copy(longest,line);
			else
				copy(longest,temp);
	   }	   
	   if(line[len-1] != '\n'){
			if(!prevmax)
				copy(temp,line);
			prevmax += len;
	   }
	   else{
			prevmax = 0;
	   }		 
	}
	if (max > 0) {   /* there was a line */ 
        printf("%s", longest); 
        if (longest[max-1] != '\n') 
             putchar('\n'); 
         printf("%d characters\n", max); 
     } 

	return 0;
}

/* getline:read a line into s,return length */
int getline(char s[],int lim)
{
	int c,i;
	for(i = 0;i <lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;	
	if(c=='\n'){
		s[i]=c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to';assume to is big enough */
void copy(char to[],char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

 