#include<stdio.h>

int a[200007];
int temp,n,mx,j;

void max_of_arry(int a[],int n,int j)
{ 
	 if(j==n)
	 {
	 	printf("%d\n",mx);
	 	return;
	 }
	 else
	 {
	 	if(a[j]>=mx)
	 	{
	 		mx=a[j];
	 	}
	 	j++;
	 	max_of_arry(a,n,j);
	 }

	  
}

int main()
{
      
     
     scanf("%d",&n);
     
     
      for(int i=0;i<n;i++)
      {
      	 scanf("%d",&a[i]);
      	 
      }

     max_of_arry(a,n,0);
    
     return 0;
 
}