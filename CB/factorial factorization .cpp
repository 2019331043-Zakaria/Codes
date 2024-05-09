#include<bits/stdc++.h>
//#define push_back pb
#define make_pair mp

using namespace std;

int main()
{
     int x;
     cin>>x;
     for(int l=1;l<=x;l++){
         int t;
         cin>>t;
         int n=100;
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

         int cnt=0;
        for(int i=0;i<25;i++)
        {
            if(prime[i]<=t)
            {

                int temp=1;
              for(;;)
              {
                   if(t/(prime[i]*temp)!=0)
                      {

                          cnt=cnt+t/(prime[i]*temp);
                           temp=prime[i]*temp;

                      }
                  else
                    break;

              }
                power.push_back(cnt);
               cnt=0;

            }

            else
                break;


        }
         cout<<"Case "<<l<<": "<<t<<" = "<<prime[0]<<" "<<"("<<power[0]<<")";

      for(int i=1;i<power.size();i++)
           cout<<" * "<<prime[i]<<" "<<"("<<power[i]<<")";

           cout<<endl;


     }

    return 0;
}
