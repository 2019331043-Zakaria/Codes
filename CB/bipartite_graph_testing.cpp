#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      10000007
#define pi       acos(-1.0)
#define test     int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
int a[100002],color[100002];
vector<int>node[100002];
bool dfs(int p,int c)
{
     a[p]=1;
     color[p]=c;
     
     for(int i=0;i<node[p].size();i++)
     {
         int temp=node[p][i];
         if(!a[temp])
         {
            if(!dfs(temp,!c))
                return 0;
         }
         else
         {
             if(color[p]==color[temp])
                return 0;
         }
     }

     return 1;

}
int main()
{      
      
      
      int j=0;
      int t;
      cin>>t;
      while(t--)
        {
          int n,m;
          cin>>n>>m;
          int x,y;
          for(int i=1;i<=n;i++)
          {
            node[i].clear();
          }

          while(m--)
          {
             cin>>x>>y;
             node[x].push_back(y);
             node[y].push_back(x);
          }
         int flag=0;
         for(int i=1;i<=n;i++)
         {
             if(!a[i])
             {
                if(!dfs(i,0)) //push edge and color
                {
                   flag=1; //if return false 
                }

             }
         }
         if(flag)
             cout<<"Scenario #"<<++j<<":\n"<<"This is not Bipartet!\n";
         else
        cout<<"Scenario #"<<++j<<":\n"<<"Yea This is Bipartet!\n";
         
         memset(a,0,sizeof(a));

        
        }

     

     

     return 0;
} 