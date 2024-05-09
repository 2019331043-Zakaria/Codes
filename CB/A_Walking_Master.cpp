/*
* @Author: Zakaria 
* @Date:   2023-03-24 14:37:51
* @Last Modified time: 2023-03-24 14:48:42
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
        
       ll a, b, c, d;
       cin>>a>>b>>c>>d;

       if(b>d)
       {
       	  cout<<-1<<endl;
       	  return ;
       }

       ll ans = d - b;

       a+=ans;

       if(a<c)
       {
       	 cout<<-1<<endl;
       	 return ;
       }

       ans+=a-c;

       cout<<ans<<endl;
      
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