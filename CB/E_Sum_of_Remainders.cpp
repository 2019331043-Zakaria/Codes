#include<bits/stdc++.h>
#define pio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ll long long int
#define sz 100005
using namespace std;
vector<ll>adj[sz],w[sz];
ll par[sz],cost[sz];
void dijstra(ll s,ll e)
{
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
        q.push({0,s});
        cost[s]=0;
        while(!q.empty()){
       ll x=q.top().first;
       ll y=q.top().second;
       //cout<<x<<y<<endl;
       q.pop();
       for(ll i=0;i<adj[y].size();i++){
        if(cost[adj[y][i]]>x+w[y][i]){
                cost[adj[y][i]]=x+w[y][i];
                q.push({cost[adj[y][i]],adj[y][i]});
                par[adj[y][i]]=y;
        }
       }
        }
        //return cost[e];

}
void init(ll n)
{
        for(ll i=0;i<n;i++){
                par[i]=-1,cost[i]=INT_MAX;
        }
}
int main()
{
        pio
        
                ll n,m,s=1,e=n;
                cin>>n>>m;
                init(n);
                for(ll i=0;i<m;i++){
                        ll x,y,z;
                        cin>>x>>y>>z;
                        x--,y--;
                        adj[x].push_back(y);
                        adj[y].push_back(x);
                        w[x].push_back(z);
                        w[y].push_back(z);
                        
                }
                dijstra(s-1,e-1);
                vector<ll>res;
                ll u=n-1;
                while(~u){
                        res.push_back(u+1);
                        u=par[u];
                        //res.push_back(u);
                }
                
                reverse(res.begin(),res.end());

                if(par[e-1]==-1){
                        cout<<-1<<endl;
                }
                else{
                for(int i=0;i<res.size();i++){
                        cout<<res[i]<<" ";
                }
                cout<<endl;
        }
        
        
}