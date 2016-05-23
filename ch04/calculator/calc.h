#include <math.h>

#define NUMBER '0' /* signal that a number was found */
#define FUNC   '1' /* signal that func was found  */


int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int c);
void dofunc(char s[]);