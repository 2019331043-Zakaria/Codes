/*
* @Author: Zakaria 
* @Date:   2022-10-15 22:15:15
* @Last Modified time: 2022-10-16 10:26:52
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
ll cost[N];
ll sum[N];
ll dis[N];
ll parent[N];
ll k_term[N];
ll ans;
ll res[N];

void dfs(int p, int par, ll k)
{
        
        
       
        ans += (cost[p]*k);
        res[p] += cost[p]*k;

        int sz = node[p].size();
        
        if(sz==0)
        	return ;
         
      //  cout<<p<<" "<<sz<<endl;

        ll pabe = k/sz;
        ll modval = k%sz;
        vector<pair<ll, int>>v;

        for(auto i:node[p])
        {
             if(i==par)
                continue;
             
             dfs(i, p, pabe);
             v.push_back({res[i], i});
        }

        sort(v.rbegin(), v.rend());

        for(int i=0 ; i<v.size() ; i++)
        {
            if(i<modval)
            ans+=v[i].f, res[p]+=v[i].f;
        }
}

void Solve()
{
        
        int n, k;
        cin>>n>>k;

        for(int i=1 ; i<=n ; i++)
        {
        	node[i].clear();
        	cost[i]=0;
        	sum[i]=0;
        	dis[i]=0;
        	ans=0;
        	parent[i]=-1;
            res[i]=0;
        }
        
        for(int i=2 ; i<=n ; i++)
        {
        	int p;
        	cin>>p;
        	node[p].push_back(i);
        }

        for(int i=1 ; i<=n ; i++)
        	cin>>cost[i];

        
       /* for(int i=1 ; i<=n ; i++)
        	cout<<i<<" "<<sum[i]<<" "<<dis[i]<<" "<<parent[i]<<endl;*/

      

        dfs(1, -1, k);
        
        

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