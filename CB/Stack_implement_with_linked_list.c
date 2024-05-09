#include<stdio.h>
#include<stdlib.h>
struct node{

   int data;
   struct node *link;


};

struct node *top=NULL;

void push(int x)
{
     struct node *newnode;

     newnode=(struct node*) malloc(sizeof(struct node));

     newnode->data=x;
     newnode->link=top;
     top=newnode;
}


void print()
{
    struct node *temp;

    temp=top;
    if(top==NULL)
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
    temp=top;
    if(temp==NULL)
        printf("Underflow\n");
    else
    {
   
        printf("The pop element is %d \n",temp->data);
        top=top->link;

        free(temp);
    }
}

int main()
{

    push(2);
    push(3);
    push(10);
    print();
    pop();
    print();
    push(12232);
    print();

    return 0;

}
