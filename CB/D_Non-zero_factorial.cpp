/*
* @Author: Zakaria 
* @Date:   2022-12-29 23:28:23
* @Last Modified time: 2022-12-29 23:52:25
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

ll Foo(ll x)
{
	 if(x==0)
	 	return 1;
	 if(x==1)
	 	return 1;
	 if(x==2)
	 	return 2;
	 if(x==3)
	 	return 6;
	 if(x==4)
	 	return 4;
	 if(x==5)
	 	return 2;
	 if(x==6)
	 	return 2;
	 if(x==7)
	 	return 4;
	 if(x==8)
	 	return 2;
	 if(x==9)
	 	return 8;

	 if(dp[x]!=-1)
	 	return dp[x];

	 if(((x/10)%10)%2)
	 	return dp[x] = 4LL*Foo(x/5)*Foo(x%10);
	 else
	 	return dp[x] = 6LL*Foo(x/5)*Foo(x%10);
}

void Solve()
{
        
      int n;
      cin>>n;
      ll temp = 1;

      for(int i=1 ; i<=n ; i++)
      {
      	  ll x;
      	  cin>>x;
      	  temp*=dp[x]%10;
      	  temp%=10;
      }

      cout<<temp<<endl;
      
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        memset(dp, -1, sizeof(dp));

        for(int i=1 ; i<=1e6 ; i++)
        {
        	dp[i] = Foo(i);
        }

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 