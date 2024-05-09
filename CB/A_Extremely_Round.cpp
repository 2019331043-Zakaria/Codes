/*
* @Author: Zakaria 
* @Date:   2022-12-12 20:35:39
* @Last Modified time: 2022-12-12 20:37:50
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

ll dp[N];

bool ok(int x)
{
	  int cnt = 0;
	  while(x)
	  {
	  	 if(x%10)
	  	 	cnt++;
	  	 x/=10;
	  }

	  return cnt==1;
}

void Solve()
{
        
      ll x;
      cin>>x;

      cout<<dp[x]<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;


        for(int i=1 ; i<N ; i++)
        {
        	 dp[i] = dp[i-1];

        	 if(ok(i))
        	 	dp[i]++;
        }
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 