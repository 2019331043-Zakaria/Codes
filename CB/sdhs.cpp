#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int n,j,i,counter=0;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(!(!a[i]))
        {
            for(j=i+1;j<n;j++)
          {
            if(a[j]==a[i])
            {
                a[j]=0;
            }
          }
          counter++;
        }
    }
  if(counter%2==0)
    printf("CHAT WITH HER!\n");
  else
     printf("IGNORE HIM!\n");

    return 0;
}

