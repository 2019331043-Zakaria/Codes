#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{

    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1][m+1];
    int sumrow=0,sumcol=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            sumrow+=a[i][j];
        }
        a[i][m]=sumrow;
        sumrow=0;
    }


    for(int j=0;j<m+1;j++)
    {
        for(int i=0;i<n;i++)
           {
               sumcol+=a[i][j];
           }
          a[n][j]=sumcol;
          sumcol=0;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }



   return 0;
}

