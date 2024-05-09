/*
* @Author: Zakaria 
* @Date:   2022-10-03 12:43:10
* @Last Modified time: 2022-10-03 14:58:22
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
const int N = 500;

ll dp[N][N];
ll a[N];
int n;

ll foo(int i, int k)
{ 
       
       
        if(i==n)
            return  0;

        if(k>N)
         return  1e9;

        if(dp[i][k]!=-1)
            return dp[i][k];

        return dp[i][k] = min(foo(i, k+1), foo(i+1, k+1) + abs(a[i]-k));
}

void Solve()
{
        
        
        cin>>n;

        for(int i=0 ; i<n ; i++)
            cin>>a[i];

        sort(a, a+n);

        memset(dp, -1, sizeof(dp));

        cout<<foo(0, 1)<<endl;
      
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