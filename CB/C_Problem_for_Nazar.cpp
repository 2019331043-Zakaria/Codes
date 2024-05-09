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

ll bigmod(ll a, ll b, ll n)
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

ll sum(ll x)
{
       
       int flag=1;
       ll cnt=1;
       ll odd=0, even=0;
       ll total=0;
       while(1)
       {
            if(flag%2)
            { 
                 if(total+cnt<=x)
                 {
                    odd+=cnt;
                    total+=cnt;
                 }
                 else
                 {
                    odd+=(x-total);
                    break;
                 }
            }
            else
            {
                 if(total+cnt<=x)
                 {
                    even+=cnt;
                    total+=cnt;
                 }
                 else
                 {
                    even+=(x-total);
                    break;  
                 }
            }

            flag++;
            cnt*=2LL;
       }

       ll oddsum = bigmod(odd, 2, mod);
       ll evensum = ((bigmod(even , 2, mod) + bigmod(even, 1, mod)))%mod;
        
       return (oddsum+evensum)%mod;


}

void Solve()
{
        
         ll l, r;
         cin>>l>>r;

         cout<<(sum(r) - sum(l-1) + mod)%mod<<endl;
         
      
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