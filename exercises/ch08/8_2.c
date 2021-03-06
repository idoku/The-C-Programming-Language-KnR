#include <fcntl.h>
#include <stdlib.h>

#include "syscalls2.h"

#define PERMS 0666 /* RW for owner,group,others */

FILE *fopen(char *name,char *mode);

main(int argc,char *argv[])
{
	FILE *fp;
    char mode;
    mode = 'w';
    fp = fopen("8_2.c", &mode);
	
    return 0;
}

/* fopen:open file,return file ptr */
FILE *fopen(char *name,char *mode)
{
	int fd;
	FILE *fp;
	
	if(*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for(fp = _iob;fp < _iob + OPEN_MAX;fp++)
		if(fp->flags.read==0 && fp->flags.write==0)
			break; /* found free slot */
	if(fp>=_iob+OPEN_MAX)
		return NULL;
	if(*mode == 'w')
		fd = creat(name,PERMS);
	else if(*mode == 'a'){
		if((fd = open(name,O_WRONLY,0))==-1)
			fd = creat(name,PERMS);
		lseek(fd,0L,2);
	}else
		fd = open(name,O_RDONLY,0);
	if(fd==-1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	 if(*mode=='r')
		fp->flags.read=1;
	 else
		fp->flags.write=1;
	return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
	int bufsize;
	if(fp->flags.read == 1 || fp->flags.eof==0 ||fp->flags.err==0)
		return EOF;
	bufsize = (fp->flags.unbuf==1)?1:BUFSIZ;
	if(fp->base==NULL)
		if((fp->base= (char *)malloc(bufsize))==NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd,fp->ptr,bufsize);
	if(--fp->cnt < 0){
		if(fp->cnt ==-1)
			fp->flags.eof=1;
		else
			fp->flags.err=1;
		return EOF;
	}
	return (unsigned char)*fp->ptr++;
}
 