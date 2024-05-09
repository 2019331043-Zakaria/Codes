#include<stdio.h>
int main()
{

    int a[]={1,2,4,5,6,5,8,2,3,8,9,0};
    int size=sizeof(a)/sizeof(a[0]);

    int count[100];

    for(int i=0;i<99;i++)
        {
            count[i]=0;
        }
    for(int i=0;i<size;i++)
        {
             count[a[i]]++;
             
           
        }
    for(int i=0;i<size;i++)
     {
         if(count[a[i]])
       {
          printf("%d ",a[i]);
          count[a[i]]=0;
       }
    }
     return 0;

}
