#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
const ll inf=LLONG_MAX;

vector<pair<int,int> >node[100003];



int n,m,w;

priority_queue< pair<int,int>, vector<pair<int ,int> >, greater<pair<int ,int > > > pq;

vector<int>ans;

void dijsk(int d,int p)
{

    vector<int>dis(100003,inf);
     pq.push({d,p});

     dis[p]=0;

     while(!pq.empty())
     {
          int curr_node=pq.top().second;
          int curr_dis=pq.top().first;

           for(int child=0;child<node[curr_node].size();child++)
           {
           	   if(node[curr_node][child].second+curr_dis<dis[node[curr_node][child].first])
           	   {
                     dis[node[curr_node][child].first]=node[curr_node][child].second+curr_dis;

                     pq.push({dis[node[curr_node][child].first],node[curr_node][child].first});

           	   }
           }



     }



}

int main()
{


      cin>>n>>m;
      int e,f,w;
      while(m--)
      {
          cin>>e>>f>>w;
          node[e].push_back({f,w});
          node[f].push_back({e,w});
      }

       cout<<23;
      dijsk(0,1);



      return 0;

}
