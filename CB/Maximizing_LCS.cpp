/*
* @Author: Zakaria 
* @Date:   2022-12-28 20:48:38
* @Last Modified time: 2022-12-28 21:00:39
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

void Solve()
{
        int n;
        cin>>n;

        string s, t;
        cin>>s;

        int m = n;

        s='*'+s;
        t = s;
        
        reverse(t.begin(), t.end());

        t='*'+t;
        
        int dp[n+1][m+1];

        memset(dp, 0 ,sizeof(dp));

        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=m ; j++)
        	{
                 if(s[i]==t[j])        // 1+lcs(i-1,j-1);
                 {
                 	dp[i][j]=1+dp[i-1][j-1];
                 }
                 else
                 	dp[i][j]=max(dp[i-1][j], dp[i][j-1]); //max(lcs(i-1, j), lcs(i, j-1))
        	}
        }

        cout<<dp[n][m]/2<<endl;
      
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