#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line,int max);

/* find: print lines that match pattern from 1st arg */
main(int argc,char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c,except = 0,number = 0,found = 0;
	while(--argc>0 && (*++argv)[0] == '-')
	{
		while(c = *++argv[0])
		{
			switch(c)
			{
				case 'x':
					except=1;
					break;
				case 'n':
					number =1;
					break;
				default:
					printf("find:illegal option%c\n",c);
					argc=0;
					found=-1;
					break;
			}
		}
	}
	if(argc!=1)
		printf("usage:find -x -n pattern\n");
	else
		while(getline(line,MAXLINE)>0)
		{
			lineno++;
			if((strstr(line,*argv)!=NULL)!=except)
			{
				if(number)
					printf("%ld:",lineno);
				printf("%s",line);
				found++;
			}
		}
		return found;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i, j;
 
  for(i = 0, j = 0; (c = getchar())!=EOF && c != '\n'; ++i)
  {
    if(i < lim - 1)
    {
      s[j++] = c;
    }
  }
  if(c == '\n')
  {
    if(i <= lim - 1)
    {
      s[j++] = c;
    }
    ++i;
  }
  s[j] = '\0';
  return i;
}
