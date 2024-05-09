/*
* @Author: Zakaria 
* @Date:   2022-09-04 20:20:02
* @Last Modified time: 2022-09-04 20:55:08
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 2e5+6;
const ll inf=LLONG_MAX;
vector<pair<ll,ll> >node[N];
vector<ll>dis(N,inf);
int n,m,w;
vector<ll>ans;
priority_queue< pair<ll,ll>, vector<pair<ll , ll> >, greater<pair<ll , ll > > > pq;
int parrent[N];


void dijsktra(ll p)
{
        
     parrent[1]=1;
     pq.push({0,p}); 
     dis[p]=0;
     ans.push_back(p);
     while(!pq.empty())
     {
          ll curr_node=pq.top().second;
          ll curr_dis=pq.top().first;
           pq.pop();
           for( pair<ll ,ll> child: node[curr_node])
           {
           	   if(child.second+curr_dis<dis[child.first])
           	   {
                        
                     parrent[child.first]=curr_node;

                     dis[child.first]=child.second+curr_dis;
                      
                     pq.push({dis[child.first],child.first});

           	   }
           }
          

     }      

}
struct 
{
	ll x, y, w;
}store[N];

void Solve()
{
      
      
      cin>>n>>m;
      ll e,f,w;
      
      
      map<pair<int, int >, ll > mp, cnt;

      vector<pair<int, int > > v;
      for(int i=1 ; i<=m ; i++)
      {
          cin>>e>>f>>w;
          v.push_back({e,f});
          store[i].x=e;
          store[i].y=f;
          store[i].w=w;

          mp[{e,f}]=LLONG_MAX;
          mp[{f,e}]=LLONG_MAX;
         // node[e].push_back({f,w});
      }
      


      for(int i=1 ; i<=m ; i++)
      {
      	  mp[{store[i].x, store[i].y}]=min(mp[{store[i].x, store[i].y}], store[i].w);
      }

      for(int i=1 ; i<=m ; i++)
      {
      	   node[store[i].x].push_back({store[i].y, min(mp[{store[i].x, store[i].y}], mp[{store[i].x, store[i].y}])});
      	   node[store[i].y].push_back({store[i].x, min(mp[{store[i].x, store[i].y}], mp[{store[i].x, store[i].y}])});
      }

      dijsktra(1);
      
      for(int i=2 ; i<=n ; i++)
      {
      	 if(dis[i]!=inf)
      	 	cout<<dis[i]<<" ";
      	 else
      	 	cout<<-1<<" ";
      }
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