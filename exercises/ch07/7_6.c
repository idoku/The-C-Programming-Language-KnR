#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Exercise 7-6. Write a program to compare two files,printing the first 
	line where they differ.
*/

#define MAXLINE 1000

FILE *fileopen(char *fname);
int getline(char *lien,int max);

int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	char line1[MAXLINE],line2[MAXLINE];
	if(argc < 3){ /* no args;copy standard input */
		fprintf (stderr, "%s: arguments required\n", argv[0]);
		exit (1);	
	}
 
		fp1 = fileopen(*++argv);
		fp2 = fileopen(*++argv);
		
	    char *o1,*o2;
		while(1)
		{
			o1 = fgets(line1,MAXLINE,fp1);
			o2 = fgets(line2,MAXLINE,fp2);
			if(o1==NULL || o2==NULL)
				break;
			if(strcmp(line1,line2)!=0){
				printf("1:%s",line1);
				printf("2:%s",line2);
				return 0;
			}
			
		}
		if(o1!=o2){
			if(o1!=NULL)
				printf("1:%s",line1);
			else
				printf("2:%s",line2);
		}
		fclose(fp1);
		fclose(fp2);
		
	 
	return 0;
}



FILE *fileopen(char *fname)
{
	FILE *fp;
	if((fp = fopen(fname,"r"))==NULL){
					fprintf (stderr, "error: on open file %s\n", fname);
					exit(1);
				}
	 return fp;
}
 

/* getline:read a line,return length */
int getline(char *line,int max)
{
	if(fgets(line,max,stdin)==NULL)
		return 0;
	else
		return strlen(line);
}