/* This is concept of sliding window*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
 
        ios::sync_with_stdio(false);
        cin.tie(0); 
        
        int n,k;
        cin>>n>>k;

        int a[n+1];

        for(int i=0;i<n;i++)
        {
           cin>>a[i];
        }

       
        int start=0,end=0;
        int sum=0;
        int mx=-1;
        
        for(int i=0;i<n;i++)
        { 
           sum+=a[i];
           end++;

           while(sum>k)
           {
               sum-=a[start];
               start++;
           }
           mx=max(mx,end-start);

        }
       

        cout<<mx<<endl;
      
        
     

     return 0;     
      
}