#include<stdio.h>
#define n 10
int queue[n];
int front=-1;
int back=-1;

void push(int x)
{

    if(back==n-1)
     {
         printf("queue is full\n");
     }
    else if(front==-1 && back==-1)
    {
        front++;
        back++;
        queue[back]=x;
    }
    else
    {
        back++;
        queue[back]=x;
    }

}

void pop()
{


    if(front==-1 && back==-1)
    {
        printf("queue is empty\n");
    }
    else if(front==back) /// only one element exist
    {
        printf("pop value is %d \n",queue[front]);
        front=-1;
        back=-1;

    }
    else
    {
        printf("pop value is %d \n",queue[front]);
        front++;
    }
    //printf("after -> front = %d back= %d\n",front,back);
}

int main()
{
     push(23);
     push(434);
     push(2121);
     pop();
     pop();
     pop();
     pop();

     return 0;

}
