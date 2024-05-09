/*
* @Author: Zakaria 
* @Date:   2022-10-01 18:32:49
* @Last Modified time: 2022-10-01 19:49:54
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

int n, s;
int a[N], b[N];
int dp[102][10002][2];
int track[N][2];

string ans="";

int foo(int i, int sum, int flag)
{
       
      

        if(i>n)
        {

        	if(sum==s)
        	{
        		

        		return 1;
        	}
        	else
        	{
        		
        		return 0;
        	}
        }

        if(~dp[i][sum][flag])
        {
        	
        	return dp[i][sum][flag];
        }
        
      
        int p = foo(i+1, sum+a[i], 1);
        if(p)
        {
        	ans[i-1]='H';
        	return dp[i][sum][flag]=1;
        }
       

        int q = foo(i+1, sum+b[i], 0);
        if(q)
        {
        	ans[i-1]='T';
        	return dp[i][sum][flag] = 1;
        }
        
        return dp[i][sum][flag] = 0;

}
void Solve()
{
        
        cin>>n>>s;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i]>>b[i];
        
        for(int i=1 ; i<=n ; i++)
        	ans+="!";

        memset(dp, -1, sizeof(dp));
        
        if(foo(1, 0, 1))
        {
        	cout<<"Yes"<<endl;
        	cout<<ans<<endl;
        }
        else
        	cout<<"No"<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 