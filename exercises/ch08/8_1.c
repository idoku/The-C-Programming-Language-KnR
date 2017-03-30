#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void filecopy(int ifp,int ofp);

/* cat:concatenate files,version 3 */
main(int argc,char *argv[])
{
	int fp;
	if(argc == 1) /* no args;copy standard input */
		filecopy(0,1);
	else{
		while(--argc>0){
			if((fp = open(*++argv,O_RDONLY))==-1){
				printf("cat:can't open %s\n",*argv);
				return 1;
			}
			else{
				filecopy(fp,1);
				close(fp);
			}			
		}		
	}
	return 0;
}

/* filecopy:copy file ifp to file ofp */
void filecopy(int ifp,int ofp)
{
	char buf[BUFSIZ];
	int n;
	while((n = read(ifp,buf,BUFSIZ))>0)
		write(ofp,buf,n);	
}