/*
* @Author: Zakaria 
* @Date:   2022-11-11 15:41:05
* @Last Modified time: 2022-11-11 16:03:04
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

int n, m, k;
ll a[N];

int foo(int startIndex, int val)
{
	   int low = startIndex, high = n;
       int ans = low;

       while(low<=high)
       {
       	   int mid = (low+high)/2;

       	   if(a[mid] - a[startIndex]<=k)
       	   {
       	   	   low = mid + 1;
       	   	   ans = mid;
       	   }
       	   else
       	   {
       	   	   high = mid - 1;
       	   }
       }

       return ans - startIndex;

}

ll fact[200008];
 
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
    for(int i=1; i<=200002; i++) fact[i] = fact[i-1] * i % mod;
}

void Solve()
{
        
        cin>>n>>m>>k;

        for(int i = 1 ; i<=n ; i++)
        	cin>>a[i];


        sort(a+1, a+n+1);

        ll ans = 0;

        for(int i = 1 ; i<=n ; i++)
        {
        	ll index = foo(i, a[i]);
        	ans += ncr(index, m-1);
        	ans %= mod;
        }

        cout<<ans<<endl;
        
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        Fact();

        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 