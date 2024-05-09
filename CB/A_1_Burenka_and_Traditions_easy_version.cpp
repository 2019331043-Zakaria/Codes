/*
* @Author: Zakaria 
* @Date:   2022-10-03 21:13:33
* @Last Modified time: 2022-10-03 21:23:54
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

        int a[n+1];

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        int dp[n+1];

        for(int i=1 ; i<=n ; i++)
        	dp[i]=INT_MAX;
        
        dp[0]=0;

        for(int i=1 ; i<=n ; i++)
        {
         	 int res=0;
          	 for(int j=i ; j>=1 ; j--)
        	 dp[i]=min(dp[i], dp[j-1] + i-j + !((res^=a[j])==0));
        }

        cout<<dp[n]<<endl;


      
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