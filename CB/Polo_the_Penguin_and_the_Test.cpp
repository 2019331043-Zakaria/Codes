/*
* @Author: Zakaria 
* @Date:   2023-04-17 23:44:13
* @Last Modified time: 2023-04-17 23:50:56
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
const int N = 105;

int dp[N][N];
int c[N], p[N], t[N];
int n, w;

int foo(int index, int rem)
{
	

	if(index==n)
	{
	
		if(rem>=0)
			return 0;
		else
			return -1e5;
	}

	int &R = dp[index][rem];

	if(R!=-1)
		return R;
	R = 0;
	R = max(R, foo(index+1, rem));

	if(t[index]<=rem)
		R = max(R, c[index]*p[index] +  foo(index+1, rem-t[index]));

	return R;

}

void Solve()
{
      
      memset(dp, -1, sizeof(dp));
      
      cin>>n>>w;

      for(int i=0 ; i<n ; i++)
      {
      	 cin>>c[i]>>p[i]>>t[i];
      }

      cout<<foo(0, w)<<endl;
      
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