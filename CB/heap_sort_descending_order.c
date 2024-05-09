#include<stdio.h>

void min_heapify(int heap[], int heap_size, int i)
{
    int left=2*i;
    int right=2*i+1;
    int lowest_index=i;
  //  printf("%d %d %d \n", i, left, right);

    if(left<=heap_size && heap[left]<heap[i])
        lowest_index=left;

    if(right<=heap_size && heap[right]<heap[lowest_index])
        lowest_index=right;

    if(lowest_index==i)
        return;
    else
    {
        int temp=heap[i];

        heap[i]=heap[lowest_index];   ///swapping largest child to parent;

        heap[lowest_index]=temp;

        min_heapify(heap, heap_size, lowest_index); ///recursive call to largest index;

    }

}


int main()
{
     int heap_size;
     scanf("%d",&heap_size);
     int heap[heap_size+1];

     for(int i=1 ; i<=heap_size ; i++)
        scanf("%d", &heap[i]);

    ///Heapify->
     for(int i=heap_size/2 ; i>=1 ;i--)
     min_heapify(heap, heap_size , i); ;

     

     /// heap sort->
     int n=heap_size;
     for(int i=heap_size ; i>1 ;i--)
     {
         int temp=heap[1];
         heap[1]=heap[i];
         heap[i]=temp;
         heap_size-=1;
         min_heapify(heap, heap_size , 1);

     }

     for(int i=1;i<=n;i++)
     printf("%d ",heap[i]);

     return 0;
}

