/*
* @Author: Zakaria 
* @Date:   2022-10-11 10:47:54
* @Last Modified time: 2022-10-11 11:59:38
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
const int N = 3e5+6;

ll fact[300008];
 
ll bigmod(ll b, ll p) 
{
    if(p == 0) return 1;
    ll h = bigmod(b, p/2);
    h = h * h % mod;
    if(p&1) h = h * b % mod;
    return h;
}
 
ll ncr(ll n, ll r) 
{
	if(n<r)
		return 0;
    return fact[n] * bigmod(fact[r] * fact[n-r] % mod, mod - 2) % mod;
}

void Fact()
{
    fact[0] = 1;
    for(int i=1; i<=300002; i++) fact[i] = fact[i-1] * i % mod;
}

void Solve()
{
       
       Fact();
       int n, k;
       cin>>n>>k;

       int a[n], b[n];
       for(int i=0 ; i<n ; i++)
       	cin>>a[i]>>b[i];

       sort(a, a+n);
       sort(b, b+n);

       ll ans=0;

       int i=0, j=0;
       int on=0;

       while(i<n && j<n)
       {
       	   if(a[i]<=b[j])
       	   {
       	   	   ans+=ncr(on, k-1);
       	   	   ans%=mod;
       	   	   on++;
       	   	   i++;
       	   }
       	   else
       	   {
       	   	    on--;
       	   	    j++;
       	   }
       }

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