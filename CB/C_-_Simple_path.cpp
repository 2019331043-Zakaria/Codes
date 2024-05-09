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

int n, x, y;
vector<int>ans;
int dis[N], dis2[N];
int ditance;

void dfs(int p, int par, int d)
{
    
     dis[p]=d;

     for(auto i:node[p])
     {
        if(i!=par)
        dfs(i, p, d+1);
     }

}

void dfs2(int p, int par, int d)
{
    
     dis2[p]=d;

     for(auto i:node[p])
     {
        if(i!=par)
        dfs2(i, p, d+1);
     }

}

void findanswer(int p, int par)
{
       
       if(dis[p]+dis2[p]==ditance)
        ans.push_back(p);

       for(auto i:node[p])
        if(i!=par)
            findanswer(i, p);

}
void Solve()
{
        
       cin>>n>>x>>y;

       for(int i=1 ; i<n ; i++)
       {
           int u, v;
           cin>>u>>v;
           node[u].push_back(v);
           node[v].push_back(u);
       }

       dfs(x, -1, 0);

       ditance=dis[y];

       dfs2(y, -1, 0);

       findanswer(x, -1);

       for(auto i:ans)
        cout<<i<<" ";
       cout<<endl;

       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 