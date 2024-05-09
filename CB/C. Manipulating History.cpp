/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-06 16:08:22
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
#define  MAX         1000002
typedef long long ll;
using namespace std;

void Solve()
{  
         
          int n;
          cin>>n;

          map<char, int>m;
          for(int i=0 ; i<=n+n ; i++)
          {
              string s;
              cin>>s;
              for(auto j:s)
                m[j]++;
          }

          for(auto i:m)
          {
              if(i.s%2)
              {
                 cout<<i.f<<endl;
                 return ;
              }
          }
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
          cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}