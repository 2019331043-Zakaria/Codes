#include<stdio.h>

#define stack_max 15 //stack size

typedef struct{

    int top;
    int data[stack_max];

} stack;

void push(stack *st, int x)
{
     if(st->top <stack_max)
     {

         st->data[st->top]=x;
         st->top+=1;

     }
     else
     {
         printf("Stack is full\n");
     }
}

int pop(stack *st )
{
    if(st->top==0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        st->top--;

        return st->data[st->top];

    }

}


int main()
{
    stack st;
    st.top=0;
    int item;

    for(int i=0;i<10;i++)
    {

           push(&st,i);

    }

    while(st.top)
    {
       item= pop(&st);
       printf("%d\n",item);
    }

    return 0;

}
