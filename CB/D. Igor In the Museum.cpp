/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-06 16:00:39
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
#define  MAX         500002
typedef long long ll;
using namespace std;

char a[1003][1003];
int vis[1003][1003];
int n, m, e, f, x, y , q;
int dx[]={-1 , 0, 1, 0 };
int dy[]={0, 1, 0, -1 };
int parentx, parenty; 
map<pair<int,int>, pair<int,int> > parent;
map<pair<int, int> , int> mp;

bool isvisit(int e,int f)
{
    if(e<1 || e>n || f<1 || f>m || vis[e][f] || a[e][f]=='*')
      return 0;
 
     return 1;
 
}
bool wall(int e, int f)
{
     if(e<1 || e>n || f<1 || f>m || a[e][f]=='.')
        return 0;
     else
        return 1;
}

void dfs(int x,int y)
{
 
      vis[x][y]=1;
      
      parent[{x,y}]={parentx, parenty};

      for(int i=0;i<4;i++)
      {
        
          if(wall(dx[i]+x, dy[i]+y))
            mp[{parentx,parenty}]++;

          if(isvisit(dx[i]+x,dy[i]+y))
            dfs(dx[i]+x,dy[i]+y);
      }
 
}
 
int main()
{
      
          

          ios::sync_with_stdio(false);
          cin.tie(0);
         
          
           cin>>n>>m>>q;
     
           for(int i=1;i<=n;i++)
           {
              for(int j=1;j<=m;j++)
              {
                 cin>>a[i][j];
                 parent[{i,j}]={i,j};
              }
           }
     
          
         
           for(int i=1;i<=n;i++)
           {
              for(int j=1;j<=m;j++)
              {
                  if(!vis[i][j] && a[i][j]=='.')
                  {   
                     
                      parentx=i;
                      parenty=j;
                      dfs(i,j);
                  }
              }
           }


     
          while(q--)
          {
                  int x, y;
                  cin>>x>>y;

                  cout<<mp[parent[{x,y}]]<<endl;
          }
 
    
      
      
     return 0;
        
       
}