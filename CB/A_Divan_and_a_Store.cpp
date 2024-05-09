/*
* @Author: Zakaria 
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2021-11-29 18:58:51
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002
#define  sz          1000005
typedef long long ll;
using namespace std;

void Solve()
{         
      
      int n;
      cin>>n;
      
       ll dp[50];
       dp[0]=0;
       dp[1]=2;

      for(int i=2 ;i<=n ; i++)
        dp[i]=dp[i-1]+dp[i-2];
      cout<<dp[n]<<endl;
       
} 

int main()
{

      ios::sync_with_stdio(false);
      cin.tie(0);

      int tt=1;
     // cin>>tt;
      while(tt--) Solve();
      
      return 0;

}