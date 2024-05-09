#include<stdio.h>

int a;

void display_menu();
void function(int choice);
void on_i();
void off_i();
void togg_i();
void stat_i();
void stat_all();
void on_ij();
void off_ij();
void togg_ij();
void togg_all();
void stat_ij();

int main(){
    int choice;
    a = 0; 
    printf("All lights are currently turned off.\n");
    display_menu();
    while(scanf("%d", &choice) != EOF){
        if(choice == 0){
            break;
        }
        function(choice);
        if(choice == 11){
            continue;
        }
        printf("Enter any option or enter 11 to display list\n");
    }
    return 0;
}

void display_menu(){
    printf("1. Turn i-th light on.\n");
    printf("2. Turn i-th light off.\n");
    printf("3. Toggle i-th light.\n");
    printf("4. Show the status of i-th light.\n");
    printf("5. Show the status of all lights.\n");
    printf("6. Turn i-th to j-th lights on.\n");
    printf("7. Turn i-th to j-th lights off.\n");
    printf("8. Toggle i-th to j-th lights.\n");
    printf("9. Toggle all lights.\n");
    printf("10. Show the status of i-th to j-th lights.\n");
    printf("0. Exit.\n");
}

void function(int choice){
    switch (choice)
    {
    case 1:
        on_i();
        break;
    case 2:
        off_i();
        break;
    case 3:
        togg_i();
        break;
    case 4:
        stat_i();
        break;
    case 5:
        stat_all();
        break;
    case 6:
        on_ij();
        break;
    case 7:
        off_ij();
        break;
    case 8:
        togg_ij();
        break;
    case 9:
        togg_all();
        break;
    case 10:
        stat_ij();
        break;
    case 11:
        display_menu();
        break;
    default:
        printf("Invalid request!!\n");
        break;
    }
}

void on_i(){
    int i;
    printf("Enter the light you want to turn on: ");
    scanf("%d", &i);
    a|=(1<<i);
}

void off_i(){
    int i;
    printf("Enter the light you want to turn off: ");
    scanf("%d", &i);
    if(a&(1<<i)){
        a^=(1<<i);
    }
}

void togg_i(){
    int i;
    printf("Enter the light you want to toggle: ");
    scanf("%d", &i);
    a^=(1<<i);
}

void stat_i(){
    int i;
    printf("Enter the light you want to check: ");
    scanf("%d", &i);
    if(a&(1<<i)){
        printf("The %d-th light is turned on.\n", i);
    } else{
        printf("The %d-th light is turned off.\n", i);
    }
}

void stat_all(){
    int i;
    for(i=0; i<25; i++){
        if(a&(1<<i)){
            printf("%d: on.\n", i);
        } else{
            printf("%d: off.\n", i);
        }
    }
}

void on_ij(){
    int i, j;
    printf("Enter the range of light you want to turn on: ");
    scanf("%d %d", &i, &j);
    if(i>j){
        a|=(((1<<(i-j+1))-1)<<i);
    } else{
        a|=(((1<<(j-i+1))-1)<<i);
    }
}

void off_ij(){
    int i, j;
    printf("Enter the range of light you want to turn off: ");
    scanf("%d %d", &i, &j);
    if(i>j){
        for(; j<=i; j++){
            if(a&(1<<j)){
                a^=(1<<j);
            }
        }
    } else{
        for(; i<=j; i++){
            if(a&(1<<i)){
                a^=(1<<i);
            }
        }
    }
}

void togg_ij(){
    int i, j;
    printf("Enter the range of light you want to toggle: ");
    scanf("%d %d", &i, &j);
    if(i>j){
        a^=(((1<<i-j+1)-1)<<j);
    } else{
        a^=(((1<<j-i+1)-1)<<i);
    }
}

void togg_all(){
    a^= ((1<<25)-1);
}

void stat_ij(){
    int i, j;
    printf("Enter the range of light you want to check: ");
    scanf("%d %d", &i, &j);
    if(i>j){
        for(;j<=i;j++){
            if(a&(1<<j)){
                printf("%d: on.\n", j);
            } else{
                printf("%d: off.\n", j);
            }
        }
    } else{
        for(;i<=j;i++){
            if(a&(1<<i)){
                printf("%d: on.\n", i);
            } else{
                printf("%d: off.\n", i);
            }
        }
    }
}
