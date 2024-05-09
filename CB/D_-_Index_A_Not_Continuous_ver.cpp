/*
* @Author: Zakaria 
* @Date:   2022-09-04 00:27:09
* @Last Modified time: 2022-09-04 15:16:05
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const ll mn = LLONG_MIN;

void Solve()
{
      int n, m;
      cin>>n>>m;
      ll a[n+1];
      
      for(int i=1 ; i<=n ; i++)
       cin>>a[i];
      
      ll dp[n+2][m+2];

      for(int i=0 ; i<=n ; i++)
      {
         for(int j=1 ; j<=m ; j++)
            dp[i][j]=LLONG_MIN, dp[i][0]=0;
      }
           
     
      for(int i=1 ; i<=n ; i++)
      {
            for(int j=1 ; j<=min(i, m) ; j++)
            {
                 dp[i][j]=max(dp[i-1][j], j*a[i] + dp[i-1][j-1]);
            }
        
      }

      cout<<dp[n][m]<<endl;
      
     



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