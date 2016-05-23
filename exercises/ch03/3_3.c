/*
 *Exercise 3-3. Write a function expand(s1,s2) that expands shorthand 
 *notations like a-z in the string s1 into the equivalent complete list 
 *abc...xyz in s2.Allow for letters of either case and digits,and be prepared
 *to handle cases like a-b-c and a-z0-9 and -a-z.Arrange that a leading or 
 *trailing - is taken literally.
*/

#include <stdio.h>

void expand(char s1[],char s2[]);
int validrange(char c1, char c2);

int main()
{
	char s1[] = "a-z a-b-c a-z0-9 -a-z";
	char s2[512];
	expand(s1,s2);
	printf("%s",s2);
	return 0;
}

void expand(char s1[],char s2[])
{
	int i,j;
	for(i=0,j=0;s1[i]!='\0';i++)
	{
	    if(s1[i]=='-')
	    {
			if(i==0 || s1[i]=='\0')
			{
				 s2[j++] = s1[i];
			}
			else
			{ 				 
				if(validrange(s1[i-1],s1[i+1]))
				{
					while(s2[j-1]<s1[i+1]){
						s2[j] = s2[j-1]+1;
						j++;
					}
					i++;						
				}else{
				   s2[j++]=s1[i];
				}
			}
	    }
	    else{
	    	s2[j++]=s1[i];
	    }
	}
	s2[j]='\0';
}


/* validrange:  returns non-zero if c1-c2 is a valid range. */ 
 int validrange(char c1, char c2) 
 { 
     if (('a' <= c1 && c1 <= 'z') && /* valid range in a-z */ 
         (c1  <= c2 && c2 <= 'z')) 
         return 1; 
     if (('A' <= c1 && c1 <= 'Z') && /* valid range in A-Z */ 
         (c1  <= c2 && c2 <= 'Z')) 
         return 1; 
     if (('0' <= c1 && c1 <= '9') && /* valid range in 0-9 */ 
         (c1  <= c2 && c2 <= '9')) 
         return 1; 
      
     return 0;   /* not a valid range */ 
 } 
