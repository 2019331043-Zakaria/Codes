#include<stdio.h>
#define n 10

int head=-1,tail=-1;
int queue[n];

void push(int x)
{
   if(head==-1 && tail==-1)
   {
       head=0,tail=0;
       queue[head]=x;
   }
   else if( (tail+1)%n == head)
   {
       printf("queue is full\n");
   }
   else
   {
       tail=(tail+1)%n;
       queue[tail]=x;

   }


}

void pop()
{

    if(head==tail && head==-1)
    {
        printf("queue is empty\n");
    }
    else if(head==tail)
    {
        printf("pop elements is = %d\n", queue[head]);
        head=-1;
        tail=-1;
    }
    else
    {

        printf("pop elements is = %d\n", queue[head]);
         head=(head+1)%n;
    }
}


int main()
{
     push(23);
     push(434);
     push(2121);
     pop();
     pop();
     pop();
     return 0;

}
