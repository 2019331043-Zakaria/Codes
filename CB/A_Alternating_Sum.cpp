/*
* @Author: Zakaria 
* @Date:   2022-09-05 09:43:01
* @Last Modified time: 2022-09-07 21:32:00
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const ll N = 5e5+6, mod = 1e9+9;

ll powa[N], powb[N];
ll n, a, b, k;

ll bigmod(ll a,ll b,ll n)
{
    ll res=1;
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

       
       cin>>n>>a>>b>>k;

       string s;
       cin>>s;
       
       ll temp=(n+1)/k;

       ll ans=0;
       ll cnta=1, cntb=1;

       for(int i=0 ; i<k ; i++)
       {
          
          if(s[i%k]=='+')
          ans+=(bigmod(b, i, mod) * bigmod(a, n-i, mod))%mod, ans%=mod;
          else
          ans-=(bigmod(b, i, mod) * bigmod(a, n-i, mod))%mod, ans+=mod, ans%=mod;

       }
       
       ll pans=a;

       ll a = ans;

       if(temp==1)
       {
           cout<<ans<<endl;
           return ;
       }

       ans=0;
       
       for(int i=k ; i<k+k ; i++)
       {

          if(s[i%k]=='+')
          ans+=(bigmod(b, i, mod) * bigmod(pans, n-i, mod))%mod, ans%=mod;
          else
          ans-=(bigmod(b, i, mod) * bigmod(pans, n-i, mod))%mod, ans+=mod, ans%=mod;
       }

       ll b = ans;


       a+=mod;
       b+=mod;
       a%=mod;
       b%=mod;


       if(a==b)
       {
          cout<<(temp*b)%mod<<endl;
          return ;
       }
       
       ll inv=b;
       inv=(inv*bigmod(a, mod-2, mod))%mod;


       
       ans = bigmod(inv, temp , mod) - 1 ;
       ans+=mod;
       ans%=mod;
       ans=a*ans;
       ans%=mod;

       inv--;
       inv+=mod;
       inv%=mod;
       inv=bigmod(inv, mod-2, mod);

       ans=ans*inv;
       ans%=mod;

       cout<<ans<<endl;
       

}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 