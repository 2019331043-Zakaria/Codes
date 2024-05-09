/*
* @Author: Zakaria 
* @Date:   2023-03-06 10:00:57
* @Last Modified time: 2023-03-06 10:33:56
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
const ll inf = LLONG_MAX;

ll dp[N][25];
ll n,x, k;
ll a[N];
ll result;

ll foo(int index, int taken)
{
	if(taken<0)
		return -1e15;
	if(index>n)
	{
		if(taken==0)
			return 0;
		else
			return -1e15;
	}

	ll &R = dp[index][taken];

	if(~R)
		return R;

	R = 0;

	ll pans = foo(index+1, taken-1) + a[index] + x;
	ll lans = foo(index+1, taken) + a[index] - x;

	if(taken)
	{
		R = pans;

		int rem = n - index + 1;
		if(rem>taken)
			R = max(R, lans);
	}
	else
	{
		R = lans;
	}

	R = max(R, 0LL);

	result = max(result, R);

	return R;
}
void Solve()
{
        
      cin>>n>>k>>x;

      for(int i=1 ; i<=n ; i++)
      	cin>>a[i];

      for(int i=0 ; i<=n ; i++)
      {
      	 memset(dp[i], -1, sizeof(dp[i]));
      }

      result = 0;
      foo(1, k);

      cout<<result<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 