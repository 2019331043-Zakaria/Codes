/*
* @Author: Zakaria 
* @Date:   2022-09-22 17:30:34
* @Last Modified time: 2022-09-22 18:47:07
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
const int N = 2e6+6;

int n;
// ll dp[N][2];

// ll foo(int turn , bool next)
// {
	   
//         int rem = turn - next;

//         if(rem<0)
//         	return 0;

//         if(rem==0 && next==1)
//         return dp[rem][next] = 1;
        
//         if(rem==1 && next==0)
//         return dp[rem][next] = 1;

//         if(dp[rem][next]!=-1)
//         	return dp[rem][next];
        
// }

ll fact[N];
 
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
     return (fact[n] * bigmod(fact[r] * fact[n-r] % mod, mod - 2) ) % mod;
}

void Fact()
{
    fact[0] = 1;
    for(int i=1; i<N; i++) fact[i] = fact[i-1] * i % mod;
}

void Solve()
{
        
         cin>>n;
         
        //  for(int i=0 ; i<=n ; i++)
        //  for(int j=0 ; j<=n ; j++)
        //  	dp[i][j]=-1;

        // cout<<foo(n, 0) + foo(n, 1);

        Fact();

        cout<<(ncr(n+n+2, n+1) - 1 + mod)%mod<<endl;
        
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 