/*
* @Author: Zakaria 
* @Date:   2022-12-29 22:10:33
* @Last Modified time: 2022-12-29 22:39:17
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
        
       int n, m;
       cin>>n>>m;


       int a[n+1][m+1];


       for(int i=1 ; i<=n ; i++)
       {
       	  for(int j=1 ; j<=m ; j++)
       	  	cin>>a[i][j];
       }



       int low = 1, high = 1e9, mid;
       int ans = 1;

       while(low<=high)
       {
       	   mid = (low+high)/2;

       	   int dp[n+1][m+1];
       	   memset(dp, 0, sizeof(dp));

       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  for(int j=1 ; j<=m ; j++)
       	   	  {
       	   	  	 if(a[i][j]<mid)
       	   	  	 	dp[i][j] = 0;
       	   	  	 else
       	   	  	 	dp[i][j] = 1;
       	   	  }
       	   }

       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  for(int j=1 ; j<=m ; j++)
       	   	  	dp[i][j]+=dp[i][j-1];
       	   }
           
           for(int j=1 ; j<=m ; j++) //dp[i][j] = subrectangle sum of (1,1) to (i,j)
           {
           	  for(int i=1 ; i<=n ; i++)
           	  	dp[i][j]+=dp[i-1][j];
           }

           bool ok = 0;
           for(int i=1 ; i<=n ; i++)
           {
           	  for(int j=1 ; j<=m ; j++)
           	  {
           	  	  if(i>=mid && j>=mid)
           	  	  {
           	  	  	  ll tot = dp[i][j];

           	  	  	  tot-=dp[i-mid][j];
           	  	  	  tot-=dp[i][j-mid];

           	  	  	  tot+=dp[i-mid][j-mid];

           	  	  	  if(tot>=mid*mid)
           	  	  	  {
           	  	  	  	ok=1;
           	  	  	  }
           	  	  }
           	  }
           }

           if(ok)
           {
           	  ans = mid;
           	  low = mid + 1;
           }
           else
           	  high = mid - 1;

        }

        cout<<ans<<endl;


      
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