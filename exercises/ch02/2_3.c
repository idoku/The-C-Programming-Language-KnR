/*
 * Exercisse 2-3. Write the function htoi(s),which converts a string of 
 * hexadecimal digits(including an optional 0x or 0X) into its equivalent
 * integer value.The allowable digits are 0 through 9,a through f,and A through F.
 */

#include <stdio.h>
#include <limits.h>

#define MAXLINE 100
#define MAXLENGTH 8 
//ffffffff;7fffffff
int getline(char line[], int lim);

int htoi(char s[],int len);


int main()
{
	int len; 
	char line[MAXLINE];
	while((len = getline(line,MAXLINE))>0){		
		printf("%s:%d\n",line,htoi(line,len));
	}
	return -1;
}


int htoi(char s[],int len)
{
	int c,i,n;
	int sum = n = 0;
	for(i = len-1; i >= 0 ; i--){
		c = s[i];
		if(i==1 && (s[i]=='x' || s[i]=='X')){
			return sum;
		}
		if(c>='0' && c<='9'){
			c=c-'0'; 	
		}
		else if(c>='a' && c<='f'){	
			c=c-'a'+10;
		}
		else if(c>='A' && c<='F'){
			c=c-'A'+10;
		}
		else{
			continue;
		}
		sum =sum + c + n*15; 
		n++;
	}
	return sum;
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