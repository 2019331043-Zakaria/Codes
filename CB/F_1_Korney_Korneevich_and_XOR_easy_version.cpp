/*
* @Author: Zakaria 
* @Date:   2022-10-04 11:04:49
* @Last Modified time: 2022-10-04 11:18:22
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

        int dp[N];

        for(int i=1 ; i<512 ; i++)
        	dp[i]=N;

        dp[0]=0;

        for(int i=1 ; i<=n ; i++)
        {
        	int temp[N];
        	for(int i=0 ; i<512 ; i++)
        		temp[i]=dp[i];

        	for(int k=0 ; k<512 ; k++)
        	{
        		if(dp[k^a[i]]<a[i])
        		temp[k]=min(dp[k], a[i]);
        	}

        	for(int i=0 ; i<512 ; i++)
        		dp[i]=temp[i];
        }
        vector<int>ans;

        for(int i=0 ; i<512 ; i++)
        {
        	 if(dp[i]<N)
        	 ans.push_back(i); 
        }
        cout<<ans.size()<<endl;
        for(auto i:ans)
        	cout<<i<<" ";
      
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