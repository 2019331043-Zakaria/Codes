#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
int main()
{

    vector<int>node[1000];
    int edge;
    cin>>edge;
    while(edge--)
    {
        int n,m;
        cin>>n>>m;
        node[n].push_back(m);
        node[m].push_back(n);
    }

    int initial;
    cout<<"initial node is "<<endl;
    cin>>initial;

    while(1)
    {

     int targetnode;
     cin>>targetnode;
     int level[100];
     memset(level,-1,sizeof(level));
    queue<int>q;
    level[initial]=0;
    q.push(initial);

    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        if(current==targetnode)
         cout<<"wr are now node "<< current<<" distance from origin to this node is "<<level[current]<<endl;
        else
        {
        for(int i=0;i<node[current].size();i++)
        {
            if(level[node[current][i]]==-1)
            {
                level[node[current][i]]=level[current]+1;
                q.push(node[current][i]);
            }

        }


    }



    }
    }
    return 0;
}
