/*
 *Exercise 3-1. Our binary search makes two testsinside the loop,when one would suffice
 *(at the price of more tests outside).Write a version with only one test inside the loop 
 *and measure the difference in run-time. 
*/

#include <stdio.h>

int binsearch(int x,int v[], int n);

int main()
{
	int v[10];
	int i=0,k=3;
	for(i=0;i<10;i++)
		v[i]=i;
	int m = binsearch(k,v,10);
	printf("%d",m);
	return 0;	
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x,int v[], int n)
{
	int low,high,mid;
	low = 0;
	high = n -1;
	while(low<high){
		mid = (low + high)/2;				
		if(x<=v[mid])
			high = mid;
		else
			low = mid+1;
	}	
	return (x==v[low])?low:-1; 
}

