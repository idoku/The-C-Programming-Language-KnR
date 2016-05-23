/*
 *  Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
 *  It is easy to draw the histogram with the bars horizontal;
 *  a vertical orientation is more chanllenging.
*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int getpeak(int counts[],int len);
void painth(int counts[], int maxlen);
void paintv(int counts[], int maxline); 

 
int main()
{
    int c,wlen,i,j,state,maxlen;
    state = OUT;
    wlen = i = 0;
    maxlen = 10;
    int hisg[maxlen+1];
    for(i=0;i<maxlen+1;i++)
        hisg[i] = 0;
    while((c=getchar())!=EOF)   
    {
        if(c==' ' || c=='\t' || c=='\n')
        {           
            hisg[wlen]++;
            wlen = 0;
            state = OUT;       
        }
        else if(state == OUT)
        {           
            state = IN;           
        }
		else if(state == IN)
        {		   
           wlen++;
		   if(wlen>maxlen)
			  wlen = maxlen;
        }       
    }       
	for(i=0;i<maxlen;i++)
		printf("%d",hisg[i]);
    painth(hisg,maxlen);
	paintv(hisg,maxlen);
    return -1;
}

int getpeak(int counts[], int len) {
  int peak = 0;
  int i;
  for (i = 0; i < len; i++) {
    peak = peak > counts[i] ? peak : counts[i];
  }
  return peak;
}

void painth(int counts[], int maxlen){
	printf("\nHorizontal histogram:\n");
	int peak = getpeak(counts, maxlen);
	int i,j;
	for(i=0;i<maxlen;i++)
    {		
        int len = counts[i] * 20 / peak + 1;		
		char bar[len];
        for(j=0;j<len-1;j++)
        {
           bar[j] = '*';
        }
		bar[j] = '\0';        
		if(i < maxlen - 1)
			printf("%2d: %s %2d\n",i+1,bar,counts[i]);
		else
			printf(">=%2d: %s %2d\n",i+1,bar,counts[i]);
    }	
}

void paintv(int counts[], int maxlen)
{
	printf("\nVertical histogram:\n");
	int i,j,h = 20;
	int peak = getpeak(counts, maxlen);
	
	int bars[maxlen];
	for(i =0;i<maxlen;i++)
		bars[i] = counts[i] * h / peak;
	
	for(i=0;i<=h;i++)
	{
		for(j=0;j<maxlen;j++)
		{
			if(bars[j] == (h - i))
			{
			   printf("%-5d", counts[j]);
			}
			else if(bars[j] > (h - i)){
			   printf("%-5c",'*');
			}
			else{
			   printf("%-5c",' ');
			}
		}
		printf("\n");
	}
	
	for (i = 0; i < maxlen; i++) {
		printf("=====");
	}
	printf("\n");
	
	for(i = 0;i< maxlen;i++)
	{
		if(i < maxlen - 1)
			printf("%-5d",i+1);
		else
			printf(">=%-5d",i+1);
	}	
}

//a abc abcde abcdefg