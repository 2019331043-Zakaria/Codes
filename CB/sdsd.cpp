#include<bits/stdc++.h>
//#define push_back pb
#define make_pair mp
#define n 150000000
using namespace std;

int main()
{

         int t;
         cin>>t;

         int v[n];
         vector<int>prime;
         vector<int>power;
          int root=sqrt(n);
       for(int i=2;i<=n;i++)
         {
             v[i]=1;
         }
         for(int i=2;i<=root;i++)

         {
             if(v[i]==1)
             {
                 for(int j=2;i*j<=n;j++)
                 {
                     v[i*j]=0;
                 }
             }
         }
         for(int i=2;i<=n;i++)
         {
             if(v[i]==1)
               prime.push_back(i);
         }


    return 0;
}

