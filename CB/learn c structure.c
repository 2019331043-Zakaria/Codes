#include<stdio.h>
#include<string.h>
int main()
{
    struct nametype{

    char first[49];
    char second[40];


    };
    struct student{
       int id;
      struct nametype name;

    };

//    int n;
//    printf("Enter the no of students\n");
//    scanf("%d",&n);
     int n=3;
    struct student st[3];

    for(int i=1;i<=3;i++){
    printf("Enter the %d no student information\n",i);
    scanf("%d ",&st[i].id);
    scanf("%s",st[i].name.first);
    scanf("%s",st[i].name.second);
    }

    for(int i=1;i<=3;i++)
    {
     printf("The information about %d no student\n",i);
     printf("ID: %d  \n",st[i].id);
     printf("name : %s %s\n",st[i].name.first,st[i].name.second);
    }

    return 0;
}

