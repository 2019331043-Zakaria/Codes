/*
* @Author: Zakaria 
* @Date:   2022-11-20 21:00:08
* @Last Modified time: 2022-11-20 21:10:13
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

vector<int>node[1000];
int vis[1000];
set<int>st[1000];

void dfs(int p)
{
	  vis[p] = 1;
      //cout<<p<<endl;
	  for(auto i:node[p])
	  {
	  	if(vis[i]==0)
	  	{
	  	    for(auto k :st[p])
	  		 st[i].insert(k);

	  		dfs(i);
	  	}
	  }

}

void Solve()
{
        
       int n;
       cin>>n;

       for(int i = 1 ; i<=n ; i++)
       	node[i].clear(), vis[i] = 0, st[i].clear();

       for(int i=1 ; i<=n ; i++)
       	st[i].insert(i);
       
       string s[n+1];

       for(int i=1 ; i<=n ; i++)
       {
           cin>>s[i];
       }

       for(int i=1 ; i<=n ; i++)
       {
       	   for(int j = 0 ; j<n ; j++)
       	   {
       	   	  if(s[i][j]=='1')
       	   	  	node[i].push_back(j+1);
       	   }
       }

       for(int i=1 ; i<=n ; i++)
       {
       	  if(vis[i]==0)
       	  {
       	  	dfs(i);

       	  	for(int i=1 ; i<=n ; i++)
       	  		vis[i] = 0;
       	  }
       }

       for(int i=1 ; i<=n ; i++)
       {
       	  cout<<st[i].size()<<" ";

       	  for(auto k:st[i])
       	  	cout<<k<<" ";

       	  cout<<endl;
       }

      // cout<<endl;






      
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