#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "syscalls.h"             
#include <sys/types.h>    /* typedefs */
#include <sys/stat.h>

//#include <dirent.h>
#include <windows.h> 
#include "dirent.h"

void fsize(char *);
void dirwalk(char *,void (*fcn)(char *));

static int inode;
/* print file sizes */
int main(int argc,char **argv)
{
 	if(argc==1){
		fsize("G:\\Image");
	}else{
		while(--argc>0)
			fsize(*++argv);
	}		
return 0;
}

/* fsize:print size of file "name" */
void fsize(char *name)
{	 
	struct stat stbuf;
	
	if(stat(name,&stbuf)==-1){		
		fprintf(stderr,"fsize:can't access %s\n",name);
		return;
	}
	if((stbuf.st_mode & S_IFMT)==S_IFDIR){		
		dirwalk(name,fsize);
	}	
	 printf("%8ld - %8ld - %8ld - %8ld - - %s -- %s\n", 
	 stbuf.st_size, stbuf.st_uid,stbuf.st_gid , stbuf.st_nlink,asctime(localtime(&stbuf.st_atime)), name);

}

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir,void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;
	
	if((dfd = opendir(dir))==NULL){
		fprintf(stderr,"dirwalk:can't open %s\n",dir);
		return;
	}
	while((dp=readdir(dfd))!=NULL){
		if(strcmp(dp->name,".") == 0
		|| strcmp(dp->name,"..") == 0){			
		 continue; /* skip self and parent */
		}
		if(strlen(dir) + strlen(dp->name)+2>sizeof(name))
			fprintf(stderr,"dirwalk:name %s%s too long\n",dir,dp->name);
		else{
			sprintf(name,"%s\\%s",dir,dp->name);					
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

/* opendir: open a directory for readdir calls */
DIR *opendir(char *dirname)
{	
	HANDLE hfind;
	WIN32_FIND_DATA fdata;	   
	
	char sPath[2048];	
	DIR *dp;
	sprintf(sPath, "%s\\*.*",dirname);  
	hfind = FindFirstFile(sPath,&fdata);	
	if(hfind == INVALID_HANDLE_VALUE||
	   (dp = (DIR*)malloc(sizeof(DIR)))==NULL){		  
		return NULL;
	}	
	//printf("y");
	memset(dp,0,sizeof(dp));
	dp->fdl = hfind; 
	return dp;
}

/* readdir: read directory entries in sequence */

static int inode=0;
Dirent *readdir(DIR *dp)
{
	int i;
	WIN32_FIND_DATA fdata;	/* local directory structure */
	HANDLE hfind;
	//struct direct dirbuf;
	static Dirent d;	/* return : protable structure */
	 
	if(!FindNextFile(dp->fdl,&fdata)){		
		return NULL;
		}	
	for(i=0;i<NAME_MAX;i++){
		d.name[i] = fdata.cFileName[i];
		if(fdata.cFileName[i]=='\0') break;
	}
	d.ino = inode++;
		
	return &d;
}

/* closedir: close directory opened by opendir */
void closedir(DIR *dp)
{
    if(dp){
		FindClose(dp->fdl);        
        free(dp);
    }
}
