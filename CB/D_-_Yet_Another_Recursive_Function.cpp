/*
* @Author: Zakaria 
* @Date:   2022-10-29 18:19:02
* @Last Modified time: 2022-10-29 18:33:06
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

map<ll, ll>dp;

ll foo(ll x)
{
	  if(x==0)
	  	return dp[x] = 1;

	  if(dp.find(x)!=dp.end())
	  	return dp[x];

      ll R = foo(x/2) + foo(x/3);

	  return dp[x] = R ; 
}

void Solve()
{
        
       ll n;
       cin>>n;
     
       cout<<foo(n)<<endl;

      
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