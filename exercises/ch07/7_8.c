/*
	Exercise 7-8.Write a program to print a set of 
	files,starting each new one on a new page,with 
	a title and a running page count for each file.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc,char *argv[]){
	int count=0;
	FILE *fp;
	char line[MAXLINE];
	void filecopy(FILE *,FILE *);
	 if (argc < 2) {
		fprintf (stderr, "%s: pattern is required\n", argv[0]);
		exit(1);
    }
		while(--argc>0){
			if((fp = fopen(*++argv,"r"))==NULL){
				printf("cat:can't open %s\n",*argv);
				return 1;
			}
			else{
				printf ("title: %s\t\tpage: %d\n\n", *argv, ++count);
				while(fgets(line,MAXLINE,fp)!=NULL){
					printf("%s",line);
				}
				printf("\n\n");				
				fclose(fp);	
			}			
			
		}		
	
	return 0;
}