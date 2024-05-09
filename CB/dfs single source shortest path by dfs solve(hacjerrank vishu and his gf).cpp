#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
vector<int>node[1001];
int vis[1001],dis[1001];
void dfs(int p,int d)
{
    vis[p]=1;
    dis[p]=d;
    for(int i=0;i<node[p].size();i++)
    {
        int temp=node[p][i];
        if(!vis[temp])
            dfs(temp,dis[p]+1);
    }

}

int main()
{


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     int x,y;
     for(int i=1;i<=n-1;i++)
     {
         cin>>x>>y;
         node[x].pb(y);
         node[y].pb(x);
     }

      dfs(1,0);
      int q;
      cin>>q;

      ll gf,ans=INT_MAX,nod=0;
     while(q--){
      cin>>gf;
      
      if(vis[gf]<ans)
      {
          ans=vis[gf];
          nod=gf;
      }
      else if(vis[gf]==ans)
      {
          if(gf<nod)
          {
              nod=gf;
          }
      }


     }
     cout<<nod<<endl;

      return 0;
 }
