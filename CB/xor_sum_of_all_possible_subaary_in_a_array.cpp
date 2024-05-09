#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
vector<int>node[100003];
int a[100003],vis[100003],dis[100003];
int cnt=0;
int n,m;
void dfs(int p,int d)
{
    vis[p]=1;
    dis[p]=d;
    cnt+=a[p];

    for(auto child:node[p])
    {
        if(a[child])
        {
           if(cnt+a[child]<=m&&vis[child]==0)
           {
              dfs(child,dis[p]+1);
              cnt--;

           }
        }
    }

}
int main()
{

       ios::sync_with_stdio(false);
       cin.tie(0);


         
       test
       {
          ll n;
          cin>>n;
          ll a[n+1];
       
            ll ans=0;
            ll temp=0;

          for(int i=1;i<=n;i++)
          {   
             cin>>a[i];
             temp=i*n+(i*(i-1));
             if(temp%2)
              ans^=a[i];
          }

          cout<<ans<<endl;

        }


       

     return 0;
}
