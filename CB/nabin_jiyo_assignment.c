#include<stdio.h>    
#include <stdlib.h>

struct infromation
{
    int roll;
    char name[50];
    char address[50];
    char semester[50];
    char cgpa[10];
};

int main()
{ 
    int n;
    scanf("%d",&n);

    struct infromation student[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&student[i].roll);
        scanf("%s%s%s%s",student[i].name,student[i].address,student[i].semester,student[i].cgpa);
    }

    for(int i=0; i<n; i++)
    {
        printf("%d %s %s %s %s\n",student[i].roll,student[i].name,student[i].address,student[i].semester,student[i].cgpa);
    }

     
return 0;  
}  
