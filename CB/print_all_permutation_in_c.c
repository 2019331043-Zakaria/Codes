#include<stdio.h>
#include<string.h>

void swap(char *temp1,char *temp2)
{
	  char temp;

	  temp=*temp1;
	  
	  *temp1=*temp2;
	  
	  *temp2=temp;

}

void permutation(char *a, int start, int end)
{

	 if(start==end)
	 	printf("%s\n", a);
	 else
	 {
	 	 for(int i=start;i<=end;i++)
	 	 {
	 

	         swap(a+start,a+i);	 	
	 	 	 
	 	 	 permutation(a,start+1,end);

	 	 	 swap(a+start,a+i);

	 	 	
	 	 }
	 }
}


int main()
{
	  
	 char s[1000];

	 scanf("%s ",s);
     
     int n=strlen(s);
     n--;
     permutation(s,0,n);


      return 0;

}