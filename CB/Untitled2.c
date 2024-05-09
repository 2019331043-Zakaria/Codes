#include<stdio.h>

void interchange(int a, int b, int c)
{
    a^=b^=a^=b;
    b^=c^=b^=c;
    printf("%d %d %d",a,b,c);
}

int main()
{
     int a,b,c;
     scanf("%d %d %d ", &a ,&b, &c);
     interchange(a,b,c);
     return 0;
}