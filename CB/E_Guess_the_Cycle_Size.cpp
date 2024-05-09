/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-09-13 00:22:16
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
#define  MAX         100002
typedef long long ll;
using namespace std;

ll query(int l, int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    ll x;
    cin>>x;
    return x;
}

void Solve()
{  
          
          for(int i=1 ; i<=25 ; i++)
          {
               ll x=query(i, i+1);
               ll y=query(i+1, i);
               if(x==-1)
               {
                  cout<<"! "<<i<<endl;
                  return;
               }
               if(x!=y)
               {
                   cout<<"! "<<x+y<<endl;
                   return ;
               }
          }
            
}

int main()
{
         
          ios_base::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
           
          int tt=1;
       //   cin>>tt;

          while(tt--)
          {
            
             Solve();
          }


          return 0;
        
}