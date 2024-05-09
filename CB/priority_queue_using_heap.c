#include<stdio.h>
int heap[2000005];
int heap_size;

void max_heapify(int heap[], int heap_size, int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest_index=i;

    if(left<=heap_size && heap[left]>heap[i])
        largest_index=left;

    if(right<=heap_size && heap[right]>heap[largest_index])
        largest_index=right;

    if(largest_index==i)
        return;
    else
    {
        int temp=heap[i];

        heap[i]=heap[largest_index];   ///swapping largest child to parent;

        heap[largest_index]=temp;

        max_heapify(heap, heap_size, largest_index); ///recursive call to largest index;

    }

}

void insert(int x)
{
    heap_size+=1;
    heap[heap_size]=x;
    int i=heap_size;

    while(i>1 && heap[i]>heap[i/2])
    {
        int parent=i/2;
        int temp=heap[parent];

        heap[parent]=heap[i]; ///swapping

        heap[i]=temp;

        i=parent;
    }

}

void pop()
{
    if(heap_size==0)
    {
        puts("queue is empty");
        return;
    }
    printf("pop elements is %d\n", heap[1]);

    heap[1]=heap[heap_size];
    heap_size--;

    max_heapify(heap, heap_size, 1); /// handle heapify case

}


int main()
{

     insert(34);
     insert(4);
     insert(232);
     insert(2323);

      pop();
      pop();
      pop();
      pop();
      pop();

    //  printf("pop elements is %d\n",heap[1]);

     return 0;
}
