#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int k=1;k<=t;k++){
    vector<int>graph[10000];
    int edge,n,q,s;
    cin>>n>>edge>>s>>q;
    while(edge--)
    {
        int n,m;
        cin>>n>>m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    cout<<"Case "<<k<<":"<<endl;
    while(q--){

    int level[100000];
    memset(level,-1,sizeof(level));
    int flag=0;
    int targetNode,origin;
    cin>>origin>>targetNode;
    queue <int> q;
    q.push(origin);
    level[origin]=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        if(current==targetNode){
                flag=1;
            cout<<"The shortest distance from "<<origin<<" to "<<targetNode<<" is "<<level[current]*s<<"."<<endl;
            break;
        }
        for(int i=0;i<graph[current].size();i++){
            if(level[graph[current][i]]==-1){
                level[graph[current][i]]=level[current]+1;
                q.push(graph[current][i]);
            }
        }
    }
    if(!flag)
        cout<<"Not possible to go from "<<origin<<" to "<<targetNode<<"."<<endl;


    }
}
   return 0;
}
