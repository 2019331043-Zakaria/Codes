#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define test     int t; scanf("%d",&t) ;while(t--)
typedef long long ll;
using namespace std;
int vis[10000];
vector<int>node[10000];

bool dfs(int p)
{
     
     vis[p]=1;
     for(int child:node[p])
     {
     	 if(vis[child]==0)
     	 {
     	 	 if(dfs(child)==1)
     	 	 	return 1;
     	 }
     	 else
     	 {
     	 	 if(vis[child]==1)
     	 	 	return 1;
     	 }
     }
     vis[p]=2;

     return 0;
}
int main()
{
     
     int n,m;
     cin>>n>>m;
     int x,y;
     while(m--)
     {
         cin>>x>>y;
         node[x].push_back(y);
         //node[y].push_back(x);

     }

     for(int i=1;i<=n;i++)
     {
     	 if(!vis[i])
     	 {
     	 	if(dfs(i))
     	 		cout<<"CYCLE";
     	 	else
     	 		cout<<"Not";

     	 }
     }

    return 0;

}