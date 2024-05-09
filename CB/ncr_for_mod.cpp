#include<bits/stdc++.h>

#define mod 1000000007
            
typedef long long ll;
using namespace std;


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
    return fact[n] * bigmod(fact[r] * fact[n-r] % mod, mod - 2) % mod;
}

void Fact()
{
    fact[0] = 1;
    for(int i=1; i<N; i++) fact[i] = fact[i-1] * i % mod;
}
int main()
{         

    
    

     Fact();

     cout<<ncr(10000, 5)<<endl;
    


    return 0;
    
}