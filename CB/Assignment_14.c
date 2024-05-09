#include <stdio.h>

main()
{
    FILE *ft, *sr, *fff;
    int i,j,n,m,age[10],a,b,k,weight;
    int mark[101][52],tm[101],tim[101];
    char name[101];
    ft=fopen("std_marks.txt", "r");
    sr=fopen("std_res.txt", "w");
    fff=fopen("std_marks_info.txt", "w");
    scanf("%d %d",&n,&m);


    for(i=0; i<n; i++)
    {
        fscanf(ft,"%s %d %d",&name, &age[i], &weight);
        fprintf(sr,"%s  ",name);
        fprintf(fff,"%s  %d ",name,age[i]);
        tm[i]=0;
        for(j=0; j<m; j++)
        {
            tim[j]=0;
            fscanf(ft,"%d",&mark[i][j]);
            fprintf(sr,"%d  ",mark[i][j]);
            tm[i]+=mark[i][j];
        }
        fprintf(sr,"%d  \n",tm[i]);
        fprintf(fff,"%d  \n",tm[i]);

    }


    ///*stdout part
    for(k=0; k<n-1; k++)
    {
        for(i=0; i<n; i++)
        {
            if(tm[i]<tm[i+1])
            {
                a=tm[i];
                tm[i]=tm[i+1];
                tm[i+1]=a;
            }
            for(j=1; j<=m; j++)
                if(mark[j-1][i]<mark[j][i])
                {
                    b=mark[j-1][i];
                    mark[j-1][i]=mark[j][i];
                    mark[j][i]=b;
                }
        }
    }

    printf("%d  ",tm[0]);
    for(i=0; i<m; i++)
        printf("%d ",mark[0][i]);
    puts("");


    return 0;
}
