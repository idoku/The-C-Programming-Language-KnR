#include <fcntl.h>
#include "syscalls.h"

/* _flushbuf: flush input buffer */
int _flushbuf(int c,FILE *fp)
{
	unsigned char uc = c;
	int bufsize,num_written;
	if((fp->flag&(_WRITE|_EOF|_ERR))!=_WRITE)
		return EOF;	
	if(fp->base==NULL && ((f->flag&_UNBUF)==0)){
		if((fp->base = (char *)malloc(bufsize))==NULL)
		{
			fp->flag |=_UNBUF;
		}else{
			fp->ptr = fp->base;
			fp->cnt = bufsize - 1;
		}
	}
	if(fp->flag&_UNBUF){
		fp->base = NULL;
		fp->cnt =0;
		if(c==EOF)
			return EOF;
		num_written = write(fp->fd,&uc,1);
		bufsize = 1;
	}else{
		if(c!=EOF)
			fp->ptr++=uc;
		bufsize = (int)(fp->ptr-fp->base);
		num_written = write(fp->fd,fp->base,bufsize);
		fp->ptr = fp->base;
		fp->cnt = bufsize -1;
	}
	if(num_written == bufsize)
		return c;
	else{
		f->flag |=_ERR;
		return EOF;
	}
	
	
}

int fflush(FILE *fp){	
	int retval,i=0;
	if(fp==NULL){
		for(i=0;i<OPEN_MAX;i++)
			if((_iob[i]->flag&_WRITE) && (fflush(_iob[i])==-1))
				retval=-1;
	}
	else{
		if((fp->flag&_WRITE)==0){
			return -1;
		_flushbuf(EOF,f);
		if(f->flag&_ERR)
			retvl=-1;		
		}
	}
	return retval;
}

int fclose(FILE *fp){
	int fd;
	if(fp==NULL){
		return -1;
	}
	fd = fp->fd;
	fflush(fp);
	fp->cnt = 0;
	fp->ptr=NULL;
	if(f->base !=NULL)
		free(f->base);
	f->base = NULL;
	f->flag =0;
	f->fd = -1;
	return close(fd);
}