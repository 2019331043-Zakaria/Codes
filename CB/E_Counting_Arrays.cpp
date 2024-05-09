/*
* @Author: Zakaria 
* @Date:   2022-12-06 15:20:49
* @Last Modified time: 2022-12-06 15:33:12
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

#define sz 2000010
bool siv[sz];
int lps[sz];

void seive()
{
    int  limit = sqrt(sz+1);
    
    for(int i=1 ; i<sz ; i++)
        lps[i] = i;

    for(int i=2 ; i<sz ; i+=2)
        lps[i] = 2;

    for (int  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (long  j = i*i; j<sz; j+=i+i)
                siv[j] = 1, lps[j] = min(lps[j], i);
}

ll fact[sz];
 
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
    for(int i=1; i<sz; i++) fact[i] = fact[i-1] * i % mod;
}

void Solve()
{
        
        int x, y;
        cin>>x>>y;

        map<int, int>primefactors;

        while(x>1)
        {
        	primefactors[(lps[x])]++;
        	x/=lps[x];
        }
        
        ll ans = 1;

        for(auto i:primefactors)
        {
        	int pans = i.s;
            ans*=(ncr(y+i.s-1, i.s));
            ans%=mod;
        }

        ans*=bigmod(2, y-1);
        ans%=mod;

        cout<<ans<<endl;

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        seive();
        Fact();

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 