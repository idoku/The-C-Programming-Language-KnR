#include <stdio.h>
 
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
 
/* count lines,words,and characters in input */
int main()
{
    int c,nl,nw,nc,state;
 
    state = OUT;
    nl = nw = nc = 0;
    while((c=getchar())!=EOF)
    {
        ++nc;
        if(c=='\n')
            ++nl;
        if(c==' ' || c=='\n' || c=='\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }       
     }    
     printf("%d %d %d\n",nl,nw,nc);
    return -1;
}

/*
Semantic definition of word, some special cases:
link word: "cat-walk"
small word: a, b,c
biiiiiig words: "a fooooooooo<40MILLIONLETTERS>ooooooo a" has 3 words
 
Texts with multiple spaces between words.
Texts bigger than 2GB
Words which contain a dash but no whitespace.
Non-ascii words.
Files in some different encoding (if your program supports that)
Characters which are surrounded by whitespace but do not contain any word characters (e.g. "hello - world")
Texts without any words
Texts with all words on a single line
*/