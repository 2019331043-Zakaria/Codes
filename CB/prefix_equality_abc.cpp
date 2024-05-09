/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-10 16:48:43
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         300002
typedef long long ll;
using namespace std;



void Solve()
{
         
         int n;
        
         cin>>n;
         
         int a[n+1],b[n+1];

         for(int i=1 ; i<=n ; i++)
          cin>>a[i];
         for(int i=1 ; i<=n ; i++)
          cin>>b[i];

        map<int , int> a_first_occur, b_first_occur;

        int pans[n+1],lans[n+1];


        for(int i=1 ; i<=n ; i++)
        {
           a_first_occur[a[i]]=n+1;
           b_first_occur[b[i]]=n+1;
           a_first_occur[b[i]]=n+1;
           b_first_occur[a[i]]=n+1;
        }

        for(int i=1 ; i<=n ; i++)
        {
             a_first_occur[a[i]]=min(a_first_occur[a[i]], i);

             b_first_occur[b[i]]=min(b_first_occur[b[i]], i);
        }

         int temp1=0,temp2=0;
        for(int i=1 ; i<=n ; i++)
        {
             temp1=max(temp1, b_first_occur[a[i]]);
             pans[i]=temp1;
             temp2=max(temp2, a_first_occur[b[i]]);
             lans[i]=temp2;

        }

   



        int q;
        cin>>q;

        while(q--)
        {
           int x,y;
           cin>>x>>y;

           if(pans[x]<=y && lans[y]<=x)
            cout<<"Yes\n";
           else
            cout<<"No\n";
        }




}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
         // cin>>tt;
          while(tt--)
          {
             Solve();
          }


          return 0;
        
}

