#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define test     int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
int n,m,p,q;
int dis[200005],a[200005],vis[200005];
vector<int>node[200005];
int cnt=1;
int in[200005];
bool bfs(int p)
{
     queue<int>q;
     q.push(p);
      vis[p]=1;
     if(p!=a[cnt])
        return 0;
      cnt++;

     while(!q.empty())
     {    
          
          int temp=q.front();
      
          q.pop();
        
        
           if(temp==1)
          {
          for(int i=1;i<=node[temp].size();i++)
          {
            
             if(!binary_search(node[temp].begin(),node[temp].end(),a[cnt]))
             {
              
               return 0;
             }
             else
             {
                if(vis[a[cnt]]==0)
                {
                   vis[a[cnt]]=1;
                  q.push(a[cnt]);
               
                }
                cnt=cnt+1;
                
             }

           }

         }
         else
         {

             for(int i=1;i<node[temp].size();i++)
          {
            
             if(!binary_search(node[temp].begin(),node[temp].end(),a[cnt]))
             {
            
               return 0;
             }
             else
             {
                if(vis[a[cnt]]==0)
                {
                   vis[a[cnt]]=1;
                  q.push(a[cnt]);
               
                }
                cnt=cnt+1;
                
             }

           }

         }

          

     }
     return 1;

}

int main()
{      
      
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        cin>>n;
        m=n-1;
        while(m--)
        {
          cin>>p>>q;
          node[p].push_back(q);
          node[q].push_back(p);

        }
        
       for(int i=1;i<=n;i++)
        cin>>a[i];

        for(int i=1;i<=n;i++)
         sort(node[i].begin(),node[i].end());

         if(bfs(1))
          cout<<"Yes\n";
         else
          cout<<"No\n";



     return 0;
        
        
}
