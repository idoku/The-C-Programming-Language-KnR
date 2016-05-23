/*
* Exercise 5-8. There is no error checking in day_of_year or month_day.Remedy this defect.
*/
#include <stdio.h>

int day_of_year(int year,int month,int day);
int month_day(int year,int yearday,int *pmonth,int *pday);

static char daytab[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main()
{
int m,d;
month_day(1988,60,&m,&d);
printf("%d,%d\n",m,d);
int i = day_of_year(1989,3,1);
printf("%d\n",i);

int t = month_day(1988,6368,&m,&d);
printf("%d\n",t);
int j = day_of_year(1989,13,1);
printf("%d",j);
return 0;
} 

/* day_of_year: set day of year from month & day */
int day_of_year(int year,int month,int day)
{	
	int i,leap;
	leap = year%4==0 && year%100!=0 || year%400==0;
	if (year < 1752 || month < 1 || month > 12 || day < 1 || day>daytab[leap][month])
			return -1;	
	for(i=1;i<month;i++)
		day+=daytab[leap][i];
	return day;
}

/* month_day: set month,day form day of year	*/
int month_day(int year,int yearday,int *pmonth,int *pday)
{
	int i,leap;
	leap = year%4==0 && year%100!=0 || year%400==0;
	if(year<1752 || yearday < 0 || yearday > (leap?366:365))
		return -1;
	for(i=1;yearday>daytab[leap][i];i++)
		yearday-=daytab[leap][i];
	*pmonth = i;
	*pday = yearday;	
	return 0;
}
