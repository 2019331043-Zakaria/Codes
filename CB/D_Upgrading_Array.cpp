/*
* @Author: Zakaria 
* @Date:   2022-09-22 00:22:29
* @Last Modified time: 2022-09-22 11:19:03
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
const int N = 5e3+6;

map<ll, int> dp;
ll a[N], b[N], g[N];
ll pre[N];

map<ll, ll>bad;

int n, m;

int foo(ll x)
{
       
       if(x==1)
       	return dp[x] = 0;

       if(dp.find(x)!=dp.end())
       	return dp[x];

       ll div=x;

       for(ll i=2 ; i*i<=x ; i++)
       {
       	   if(x%i==0)
       	   {
       	   	div=i;
       	   	break;
       	   }
       }

       if(bad[div])
       	return dp[x] = foo(x/div)-1;
       else
       	return dp[x] = foo(x/div)+1;

}

void Solve()
{
        
        cin>>n>>m;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        for(int i=1 ; i<=m ; i++)
        	cin>>b[i], bad[b[i]]=1;
        
        ll ans=0;

        for(int i=1 ; i<=n ; i++)
         dp[a[i]]=foo(a[i]), ans+=dp[a[i]];

        for(int i=1 ; i<=n ; i++)
         g[i]=GCD(g[i-1], a[i]);

        
        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=0 ; j<i ; j++)
        	{
        	      
        	      pre[i] = max(pre[i], pre[j] - dp[g[i]]*(i-j));

        	}
        }

        ll res=0;

        for(int i=1 ; i<=n ; i++)
        	res=max(res, pre[i]);

        cout<<ans+res<<endl;



      
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