#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;

};

void print(struct node *head)
{
    if(head==NULL)
    printf("NO Data\n");

    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    printf("\n");
}

void add_back(struct node *head,int x)
{
   struct node *ptr,*ptr1;

   ptr1=(struct node*)malloc(sizeof(struct node));


   ptr1->data=x;
   ptr1->link=NULL;

   ptr=head;

   while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }

    ptr->link=ptr1;
}

struct node* add_front(struct node *head,int x)
{
    struct node *ptr2=malloc(sizeof(struct node ));

    ptr2->data=x;
    ptr2->link=NULL;


    ptr2->link=head;
    head=ptr2;

    return head;

}

void add_certain_position(struct node *head ,int x,int p)
{
    struct node *temp,*ptr;

    temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->link=NULL;
    ptr=head;
    p--;
    while(p!=1)
    {
        ptr=ptr->link;
        p--;
    }
    temp->link=ptr->link;
    ptr->link=temp;


}

struct node* del_first_node(struct node *head)
{

    if(head==NULL)
    {
        printf("List is already Empty\n");
    }
    else
    {
        struct node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;

    }
    return head;
}

struct node* del_last_node(struct node *head)
{
    if(head==NULL)
        printf("List is already empty\n");

    if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp,*temp1;
        temp1=head;
        temp=head;
        while(temp->link!=NULL)
        {
            temp1=temp;
            temp=temp->link;
        }
        temp1->link=NULL;
        free(temp);
        temp=NULL;

    }
    return head;


}


int main()
{

     struct node *head=NULL;

     head = malloc(sizeof(struct node));
     head->data=45;
     head->link=NULL;



     struct node *current=NULL;
     current=malloc(sizeof(struct node));

     current->data=55;
     current->link=NULL;
     head->link=current;

     current=malloc(sizeof(struct node));
     current->data=67;
     current->link=NULL;
     head->link->link=current;
//1.
//print all elemsets--------------
     printf("print list\n");
     print(head);
//--------------------------------

//2.
//Insert a new node end of the linked list and print it----------------------
     printf("Enter a Number to insert Back:\n");
     int temp;
     scanf("%d",&temp);

     add_back(head,temp);

      print(head);
//------------------------------------------------------------------------

//3.
// Insert a node front of the linked list---------
     printf("enter a number to insert front\n");
     scanf("%d",&temp);
     head = add_front(head,temp);
     print(head);
//------------------------------------------------------------------------

//4.
// Add a Node in a Certain Position---------------------------------------
     printf("Enter a Data and The Position\n");
     int pos;
     scanf("%d %d",&temp,&pos);
     add_certain_position(head,temp,pos);
     print(head);
//------------------------------------------------------------------------

//5.
// Deleting the first node------------------------------------------------

      head = del_first_node(head);
      printf("After Deleting First Node\n");

      print(head);

//-----------------------------------------------------------------------

//6.
//Deleting The Last Node-------------------------------------------------
     head = del_last_node(head);
     printf("deleting Last Node\n");
     print(head);
//-----------------------------------------------------------------------


     return 0;

}
