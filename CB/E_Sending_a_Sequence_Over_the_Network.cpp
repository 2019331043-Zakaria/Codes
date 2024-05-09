/*
* @Author: Zakaria 
* @Date:   2022-10-11 21:11:42
* @Last Modified time: 2022-10-13 16:31:09
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
        memset(dp, 0, sizeof(dp));

        dp[0]=1;

        for(int i=1 ; i<=n ; i++)
        {
        	

        	if(i+a[i]<=n && dp[i-1])
        	{
        	   dp[i+a[i]]=1;
        	}

        	if(i-a[i]>0)
        	{
        		if(i-a[i]-1>=0 && dp[i-a[i]-1])
        		dp[i]=1;
        	}
        }

        if(dp[n])
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;


      
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