/*
* @Author: Zakaria 
* @Date:   2023-01-30 16:07:41
* @Last Modified time: 2023-01-30 16:12:58
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

vector<int>node[N];
int dis[N];
void Solve()
{
        
      int n, c;
      cin>>n>>c;
      for(int i=1 ; i<=n ; i++)
      	node[i].clear(), dis[i] = n+1;
      int a[n];
      
      a[0] = c;

      for(int i=1 ; i<n ; i++)
      {
      	 cin>>a[i];
      }

      for(int i=1 ; i<n ; i++)
      {
      	 int u, v;
      	 cin>>u>>v;
      	 node[u].push_back(v);
      	 node[v].push_back(u);
      }

      int ans = n+1;

      for(int i=0 ; i<n ; i++)
      {
      	 if(i)
      	 {
      	 	ans = min(ans, dis[a[i]]);
      	 	cout<<ans<<" ";
      	 }

      	 queue<int>q;
      	 dis[a[i]] = 0;
      	 q.push(a[i]);

      	 while(q.size())
      	 {
      	 	int parent = q.front();
      	 	q.pop();

      	 	for(auto child : node[parent])
      	 	{
      	 		if(dis[parent]+1 < dis[child] && dis[parent]+1<ans)
      	 		{
      	 			dis[child] = dis[parent] + 1;
      	 			q.push(child);
      	 		}
      	 	}
      	 }
      }

      cout<<endl;


      
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