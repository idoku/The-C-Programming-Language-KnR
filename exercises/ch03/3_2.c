/*
 *Exercise 3-2. Write a function escape(s,t) that converts 
 *characters like newline and tab into visible escape sequences 
 *like \n and \t as it copies this string t to s.Use a switch.
 *Write a function for the other direction as well,converting escape 
 *sequences into the real characters.
*/

#include <stdio.h>

void escape(char s[],char t[]);

void unescape(char s[],char t[]);

int main()
{
	char t[100];
	char s[] = "fda\tdaa\rghi\rjkl\tm\no\tpqr\n";
	escape(s,t);
	printf("%s\n",t);
	unescape(t,s);
	printf("%s",s);
	return 0;
}

void escape(char s[],char t[])
{
	int i=0,j=0;
	while(s[i]!='\0'){
		char c = s[i++];
		switch(c)
		{
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';				
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';		
				break;
			case '\r':
				t[j++] = '\\';
				t[j++] = 'r';		
				break;
			default:
				t[j++]=c;
				break;
		}
	}
	t[j]='\0';
}


void unescape(char s[],char t[])
{
	int i=0,j=0;
	while(s[i]!='\0'){
		char c = s[i++];
		if(c=='\\')
		{
			char v = s[i++];
			switch(v)
			{
				case 't':
					t[j++]='\t';
					break;
				case 'n':
					t[j++]='\n';
					break;
				case 'r':
					t[j++]='\r';
					break;
				default:
					t[j++]=c;
					break;
			}
		}
		else{
			t[j++] = c;
		}		
	}
	t[j]='\0';
}

