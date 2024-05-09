/*
* @Author: Zakaria 
* @Date:   2023-04-07 14:20:32
* @Last Modified time: 2023-04-07 15:05:37
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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt[1005][1005];
int ans[1005][1005];
int a[1005][1005];

void Solve()
{
        
      int n, m;
      cin>>n>>m;

      
      for(int i=1 ; i<=n ; i++)
      {
      	 for(int j=1 ; j<=m ; j++)
      	 	cnt[i][j] = 0, ans[i][j] = 0;
      }


      for(int i=1 ; i<=n ; i++)
      {
      	   for(int j=1 ; j<=m ; j++)
      	   {
      	   	  cin>>a[i][j];
      	   	  cnt[i][j]++;
      	   	  for(int k=0 ; k<4 ; k++)
      	   	  {
      	   	  	   if(i+dx[k]>=1 && i+dx[k]<=n && j+dy[k]>=1 && j+dy[k]<=m)
      	   	  	   	  cnt[i][j]++;
      	   	  }
      	   }
      }

      for(int i=1 ; i<=n ; i++)
      {
      	  for(int j=1 ; j<=n ; j++)
      	  {
      	  	   int p;
      	  	   cin>>p;

      	  	   if(p==a[i][j])
      	  	   {
      	  	   	   if(cnt[i][j]%2)
      	  	   	   	ans[i][j] = 1;
      	  	   	   else
      	  	   	   	ans[i][j] = 2;
      	  	   }
      	  	   else
      	  	   {
      	  	   	   if(cnt[i][j]%2)
      	  	   	   	ans[i][j] = 2;
      	  	   	   else
      	  	   	   	ans[i][j] = 1;
       	  	   }
      	  }
      }

      cout<<n*m<<endl;
      for(int i=1 ; i<=n ; i++)
      {
      	  for(int j=1 ; j<=m ; j++)
      	  	cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
      }




      
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