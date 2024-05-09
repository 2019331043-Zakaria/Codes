/*
* @Author: Zakaria 
* @Date:   2023-02-27 22:59:44
* @Last Modified time: 2023-02-27 23:29:28
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
        
      int n, k;
      cin>>n>>k;

      int a[n];
      for(int i=0 ; i<n ; i++)
      {
      	cin>>a[i];
      }

      ll cold[k+1];

      for(int i=1 ; i<=k ; i++)
      	cin>>cold[i];

      ll hot[k+1];

      for(int i=1 ; i<=k ; i++)
      	cin>>hot[i];

      
      ll ans = 0;
      map<int, int>vis;

      map<int, int>done;

      queue<int>q;
      q.push(a[0]);

      ans+=cold[a[0]];
      vis[a[0]] = 1;
      done[0] = 1;

      while(q.size())
      {
      	int x = q.front();
      	q.pop();

      	for(int i=0 ; i<n-1 ; i++)
      	{
      		if(vis[a[i]])
      		{
      			if(done[i+1])
      				continue;
      			else
      			{
      				if(vis[a[i+1]])
      					ans+=hot[a[i+1]], done[i+1] = 1;
      				else
      				{
      					ans+=cold[a[i+1]];
      					vis[a[i+1]] = 1;
      					done[i+1] = 1;
      				}
      			}
      		}
      	}
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