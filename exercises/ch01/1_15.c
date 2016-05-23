/*
 *  Exercise 1-15. Rewrite the temperature conversion program of 
 *  Section 1.2 to use a function for conversion.
*/

#include<stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0,20,...,300  */
/* version 2 FarToCel function  */
int far2cel(int far);

int main()
{
	float fahr,celsius;
	int lower,upper,step;
	lower=0;  	/* lower limit of temperature table */
	upper=300; 	/*  upper limit */
	step=20;   /*  step size */
	fahr = lower;
	printf("fahr celsius\n");
	while(fahr<=upper){
		celsius = far2cel(fahr);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr + step;
	}
	return 0;
}

int far2cel(int far)
{
	int cel = (5.0/9.0) * (far-32.0);
	return cel;
}