#include <fcntl.h>
#include "syscalls.h"
#include <stdlib.h>
 
int fseek(FILE *fp,long offset,int origin){
	if((fp->flag&_UNBUF)==0 && fp->base !=NULL){
		if(fp->flag&_WRITE){
			fflush(fp);
		}else if(fp->flag&_READ){
			fp->cnt=0;
			fp->ptr=fp->base;
		}
	}
	return (lseek(fp->fd,offset,origin)<0);
}