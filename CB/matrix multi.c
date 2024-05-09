#include<stdio.h>

int main()
{
    int roll;
    printf("Roll No : ");
    scanf("%d", &roll);

    char name[50];
    printf("Name of Student : ");
    scanf("%s", name);

    int physics, Chemistry, Computer_Application;

    printf("Marks is Physics : ");
    scanf("%d", &physics);

    printf("Marks is Chemistry : ");
    scanf("%d", &Chemistry);

    printf("Marks is Computer Application : ");
    scanf("%d", &Computer_Application);

    int total = physics + Chemistry + Computer_Application;

    double percentage = (total*1./3)*100.;





    return 0;
}
