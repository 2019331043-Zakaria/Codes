/*
* @Author: Zakaria 
* @Date:   2022-10-29 18:03:04
* @Last Modified time: 2022-10-29 18:14:09
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

const int mod = 998244353;
const int N = 2e5+6;

ll bigmod(ll a,ll b,ll n)
{
    ll res=1;
    if(b==0)
        return 1;
    a=a%n;
    if(a==0)
        return 0;
    while(b>0)
    {

            if(b%2)
            res=(res*a)%n;
            b=b/2;
            a=(a*a)%n;
    }
    return res;
}
void Solve()
{
        
      ll a, b, c, d, e, f;
      cin>>a>>b>>c>>d>>e>>f;
      
     
       
      ll ans = a%mod;
      ans*=(b%mod);
     // cout<<ans<<endl;
      ans%=mod;
      ans*=(c%mod);
      ans%=mod;
      
     // cout<<ans<<endl;
      
      ll pans = ans;

      ans = d%mod;
      ans*=(e%mod);
      ans%=mod;
      ans*=(f%mod);
      ans%=mod;

    //  cout<<ans<<endl;
      
     
     
      cout<<(pans - ans + mod)%mod<<endl;



      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 