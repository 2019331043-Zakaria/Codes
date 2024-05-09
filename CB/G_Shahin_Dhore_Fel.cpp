/*
* @Author: Zakaria 
* @Date:   2023-03-18 17:08:17
* @Last Modified time: 2023-03-18 17:12:01
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
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

void Solve()
{
        
      ll x, u, v;
      cin>>x>>u>>v;

      if(x==0)
      {
      	 cout<<0<<endl;
      	 return ;
      }

      if(u<=v)
      {
      	 cout<<-1<<endl;
      	 return ;
      }

      double ans = (x*1./(u-v));

      cout<<fixed<<setprecision(10)<<ans<<endl;
      
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