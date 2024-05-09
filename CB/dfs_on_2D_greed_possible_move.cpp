#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
vector<int>node[100003];

int cnt[100003],dis[100003];
int vis[22][22];
char a[22][22];

int movex[]={-1, 0, 1, 0};
int movey[]={0, 1, 0, -1};
int n,m;
bool isvisit(int c,int d)
{
      if(c<1||c>n||d<1||d>m)
        return 0;
      if(vis[c][d]||a[c][d]=='#')
        return 0;
      return 1;

}


void dfs(int p,int q)
{
     vis[p][q]=1;
     for(int i=0;i<4;i++)
     {
         if(isvisit(movex[i]+p,movey[i]+q))
          
          dfs(movex[i]+p,movey[i]+q);
     }
}

int main()
{
           int j=0;
           test
           {
           int x,y;
           cin>>n>>m;
           swap(n,m);
          for(int i=1;i<=n;i++)
          {
             for(int j=0;j<=m;j++)
              vis[i][j]=0,a[i][j]=0;
          }

           for(int i=1;i<=n;i++)
           {
              for(int j=1;j<=m;j++)
                {
                  cin>>a[i][j];
                     
                     if(a[i][j]=='@')
                     {
                       x=i,y=j;
                     }
                }

           }

           dfs(x,y);
            
            int ans=0;
            for(int i=1;i<=n;i++)
            {
               for(int j=1;j<=m;j++)
               { 
                   if(vis[i][j])
                    ans++;
               }
            }
          
           cout<<"Case "<<++j<<": "<<ans<<endl;

      
           }
 
 
     return 0;
}