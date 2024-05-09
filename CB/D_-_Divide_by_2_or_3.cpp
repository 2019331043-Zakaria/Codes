/*
* @Author: Zakaria 
* @Date:   2022-11-05 18:18:15
* @Last Modified time: 2022-11-05 18:49:09
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

set<int>v;
int n;
ll a[N];

void foo(int x)
{
	   if(x%2==0)
	   {
	   	  v.insert(x/2);
	   	  foo(x/2);
	   }
	   if(x%3==0)
	   {
	   	  v.insert(x/3);
	   	  foo(x/3);
	   }
}
map<ll, int> f;

int dp(int index, ll val)
{
	   if(val==a[index])
	   	return 0;
	   if(val>a[index])
	   	return 1e9;

	   if(f.find(val)!=f.end())
	   	return f[val];

	   ll pans = 1+min(dp(index, 2*val), dp(index, 3*val));
	   return f[val] = pans;
}


void Solve()
{
        
        cin>>n;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        v.insert(a[1]);
        foo(a[1]);

         
        ll ans = 1e9;

        for(auto k:v)
        {
        	ll temp = 0;

        	for(int i=1 ; i<=n ; i++)
        	{
        		temp+=dp(i, k);
        		f.clear();
        	}

        	ans = min(ans, temp);
        }

        if(ans==1e9)
        	cout<<-1<<endl;
        else
        	cout<<ans<<endl;




      
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