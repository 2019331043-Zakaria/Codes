#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
vector<int>node[100003];
int a[100003],dis[100003];
ll ans;
void dfs(int p,int d)
{
    a[p]=1;
    dis[p]=d;
    for(auto child:node[p])
    {
       if(a[child]==0)
        dfs(child,dis[p]+1);
    }

}
int main()
{

       ios::sync_with_stdio(false);
       cin.tie(0);
        
            int n,m;
            cin>>n>>m;
           

            int x,y;
            while(m--)
            {
               cin>>x>>y;
               node[x].push_back(y);
               node[y].push_back(x);
            }

           dfs(1,0);
          
         int p1=0,p2=0;
          int mx=0;
         for(int i=1;i<=n;i++)
         {
           if(dis[i]>=mx)
           {
             p1=i;
             mx=dis[i];
           }

         }
       
       memset(a,0,sizeof(a));
       memset(dis,0,sizeof(dis));
       dfs(p1,0);

       for(int i=1;i<=n;i++)
        cout<<dis[i]<<endl;

       


     return 0;
} 
