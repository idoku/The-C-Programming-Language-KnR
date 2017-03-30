#include <stdio.h>
#include <stdlib.h>

void *calloc(unsigned,unsigned);

int main()
{
	int *p = NULL;
	int i=0;
	p = calloc(10,sizeof *p);
	if(p==NULL)
		printf("calloc returned NULL");
	else{
		for(i=0;i<10;i++){
			printf("%08X",p[i]);
			if(i % 8 == 7){
				printf("\n");
			}	
		}
	}
	free(p);
	return 0;
}

void *calloc(unsigned n,unsigned size)
{
	 unsigned i,nb;
	 char *p,*q;
	 nb = n * size;
	 if((p = q = malloc(nb))!=NULL){
		for(i = 0;i<nb;i++)
			*p++=0;
	 }
	 return q;
}
 