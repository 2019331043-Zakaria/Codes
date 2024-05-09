#include<stdio.h>
int main()
{
    char c='A';
    char *p,**q;
    p=&c;
    q=&p;
    **q='B';
    printf("%c\n",**q );

    return 0;
}