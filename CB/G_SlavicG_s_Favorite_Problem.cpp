/*
* @Author: Zakaria 
* @Date:   2022-11-21 22:04:28
* @Last Modified time: 2022-11-23 13:09:43
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

int n, a, b;
vector< pair<ll , ll > >node[N];
ll xb[N];
map<ll, ll>m;
ll xa[N];
set<ll>sta, stb;

void dfsb(int p, int par, int pans)
{

      int val = pans;
      if(p!=b)
      stb.insert(val);
      for(auto i:node[p])
      {
        if(i.f==par)
            continue;
        pans^=i.s;
        dfsb(i.f, p, val^i.s);
      }
}

void dfsa(int p, int par, int pans)
{
      int val = pans;
      sta.insert(val);
      xa[p] = val;
      if(p==b)
        return ;


      for(auto i:node[p])
      {
        if(i.f==par)
            continue;
        dfsa(i.f, p, val^i.s);
      }
}

void Solve()
{
        
     
      cin>>n>>a>>b;

      for(int i=1 ; i<=n ; i++)
        xa[i] = 0, xb[i] = 0, node[i].clear();

      sta.clear();
      stb.clear();

      for(int i=1 ; i<n ; i++)
      {
             int u, v, w;
             cin>>u>>v>>w;

             node[u].push_back({v, w});
             node[v].push_back({u, w});
      }

      dfsa(a, -1, 0);

      dfsb(b, -1, 0);

     

      for(int i=1 ; i<=n ; i++)
      {
          if(i==b)
          {
            if(xa[i]==0)
            {
                cout<<"YES"<<endl;
                return ;
            }
          }
          else if(stb.find(xa[i])!=stb.end())
          {
              cout<<"YES"<<endl;
              return ;
          }
      }

      cout<<"NO"<<endl;

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