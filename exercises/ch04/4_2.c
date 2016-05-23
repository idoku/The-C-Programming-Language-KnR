/*
*Exercise 4-2. Extend atof to handle scintific notation of the formm 123.45e-6 
*where a floating-point number may be followed by e or E and an optionally signed exponent.
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100
/* atof: convert string s to double */
double atof (char s[]);
/* getline: get line into s,return length */
int getline(char s[],int lim);

int main()
{
	double sum,atof(char []);
	char line[MAXLINE];
	int getline(char line[],int max);
	sum =0;
	while(getline(line,MAXLINE)>0)
		printf("\t%g\n",sum+=atof(line));
	return 0;
}

/* atof: convert string s to double */
double atof (char s[])
{
	double val,power,exp;
	int i,sign,esign;
	for(i=0;isspace(s[i]);i++) /* skip white space */
	{
		;
	}	
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0;isdigit(s[i]);i++)
	{
		val=10.0*val + (s[i] - '0');
	}
	if(s[i]=='.')
		i++;
	for(power = 1.0;isdigit(s[i]);i++)
	{
		val = 10.0 * val +(s[i] -'0');
		power *=10.0;
	}
	val = sign *val/power;	
	if(s[i] == 'e' || s[i]=='E')
	{
		i++;
		esign = (s[i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(power = 0.0;isdigit(s[i]);i++)
		{
			exp = 10 * exp + (s[i] - '0');
		}
		val *= pow(10,esign*exp);
	}
	return val;
}

/* getline: get line into s,return length */
int getline(char s[],int lim)
{
	int c,i;
	i = 0;
	while(--lim>0&& (c=getchar())!=EOF && c!='\n')
		s[i++] = c;
	if(c=='\n')
		s[i++] = c;
	s[i]='\0';
	return i;
}