#include <stdio.h>
#include <string.h>

void fun(int a[][],n,m)
{
    for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        printf("%d ",a[i][j]);
   }
}
// Driver program
int main()
{
   int n,m;
   scanf("%d %d ",&n,&m);
   int a[n][m];

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        scanf("%d ",&a[i][j]);
   }
   fun(a,n,m);
   return 0;
}


