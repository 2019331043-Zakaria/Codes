/*
* @Author: Zakaria 
* @Date:   2022-09-29 21:03:32
* @Last Modified time: 2022-09-30 12:42:19
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

const int mod = 998244353 ;
const int N = 2e5+6;

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
        
        ll n;
        cin>>n;
    
        ll dp[2][n+1];

        dp[0][2]=1;
        dp[1][2]=0;

        for(int i=4 ; i<=n ; i++)
        {
             dp[0][i] = (ncr(i-1, i/2 - 1) + dp[1][i-2])%mod;

             dp[1][i] = ncr(i, i/2);
             dp[1][i] -= dp[0][i];
             dp[1][i] += mod;
             dp[1][i] %= mod;
             dp[1][i] -= 1;
             dp[1][i] %= mod;
        }  

        cout<<dp[0][n]<<" "<<dp[1][n]<<" "<<1<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        Fact();

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 