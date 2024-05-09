#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#define n 10000000
using namespace std;
int main()
{


            int t;
         cin>>t;
             char v[n];
             int prime[10000];
           int cnt=0;
          int root=sqrt(n);
         for(int i=2;i<=n+2;i++)
         {
           v[i]=1;
         }
         int j=0;
         for(int i=2;i<=n+2;i++)

         {
             if(v[i]==1)
             {

                    prime[j]=i;
                    j++;
                 //  cnt++;
                 for(int j=2;i*j<=n;j++)
                 {
                     v[i*j]=0;
                 }
             }
         }
      cout<<prime[t-1]<<endl;



    return 0;
}
