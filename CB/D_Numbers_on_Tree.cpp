/*
* @Author: Zakaria 
* @Date:   2022-09-15 10:58:30
* @Last Modified time: 2022-09-15 20:39:46
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
const int N = 2e3+6;

int cost[N];
vector<int>node[N];
int subtree[N];
int ans[N];
vector<int>path;


int dfs(int p, int par)
{
       int cur=1;
       for(auto i:node[p])
       {
       	  if(i!=par)
       	  	cur+=dfs(i, p);
       }
       subtree[p]=cur;
       return cur;

}

void update(int p, int par)
{
      
       int temp = path[cost[p]];
       ans[p]=temp;
       vector<int>pans;
       for(auto i:path)
       {
           if(i!=temp)
            pans.push_back(i);
        }
       path=pans;

       for(auto i:node[p])
       {
          if(i!=par)
            update(i, p);
       }

}

void Solve()
{
        
        int n;
        cin>>n;
        int root=1;

        for(int i=1 ; i<=n ; i++)
        {
            path.push_back(i);
        	int p;
        	cin>>p>>cost[i];
        	if(p==0)
        		root=i;
        	else
        	{
        		node[p].push_back(i);
        		node[i].push_back(p);
        	}
        }
       

       dfs(root, -1);

       for(int i=1 ; i<=n ; i++)
       	subtree[i]--;

       for(int i=1 ; i<=n ; i++)
       {
          if(cost[i]>subtree[i])
          {
             cout<<"NO"<<endl;
             return ;
          }
       }

       update(root, -1);
       cout<<"YES"<<endl;
       for(int i=1 ; i<=n ; i++)
        cout<<ans[i]<<" ";
       cout<<endl;
       
       
      
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