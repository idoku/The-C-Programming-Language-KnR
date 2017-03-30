/*
Exercise 7-7.Modify the pattern finding program of Chapter 5 to take its input from a set of named 
files or,if no files are named as arguments,from the standard input.Should the file name be printed 
when a matching line is found?
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

void pattern_search(FILE *fp,char *pattern);

int main(int argc, char *argv[]){
	FILE *fp;
	if (argc < 2) {
		fprintf (stderr, "%s: pattern is required\n", argv[0]);
		exit(1);
    }
	char pattern[MAXLINE];
	strcpy(pattern,*++argv);
	 
	 if(argc>2){
		while(*++argv){
			if((fp = fopen(*argv,"r"))==NULL){
				printf("can't open %s\n",*argv);
				return 1;
			}
			else{
				pattern_search(fp,pattern);
				fclose(fp);
			}
	}
	}
	return 0;
}

void pattern_search(FILE *fp,char *pattern){
	char line[MAXLINE];
	while(fgets(line,MAXLINE,fp)!=NULL){
		if(strstr(line,pattern)){
			printf("%s",line);
		}
	}
}