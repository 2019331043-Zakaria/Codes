#include<stdio.h>
#include<stdlib.h>
struct node{

   int data;
   struct node *link;


};

struct node *front=NULL;
struct node *back=NULL;

void push(int x)
{
     struct node *newnode;

     newnode=(struct node*) malloc(sizeof(struct node));

     newnode->data=x;
     newnode->link=NULL;

     if(front==NULL ) ///queue is empty;
     {
         front=newnode;
         back=newnode;
     }
     else
     {
         back->link=newnode;
         back=newnode;
     }
}


void print()
{
    struct node *temp;

    temp=front;
    if(front==NULL && back==NULL)
        printf("Stack is empty\n");
    else
    {
      while(temp!=NULL)
      {
        printf("%d\n",temp->data);
        temp=temp->link;
      }

    }
}

void pop()
{
    struct node *temp;
    temp=front;

     if(front==NULL)
        printf("Stack is empty\n");
    else
    {
        front=front->link;
        printf("The pop element is %d \n",temp->data);
        free(temp);
    }
}

int main()
{
    pop();
    push(2);
    push(3);
    push(10);
    print();
    pop();
    pop();
    pop();
    pop();
    push(12232);
    print();
    push(3);
    push(10);
    print();
    pop();
    print();

    return 0;

}
