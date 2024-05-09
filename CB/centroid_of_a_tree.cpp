#include<bits/stdc++.h>
#define pb       push_back
#define f        first
#define s       second
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
int vis[100005],dis[100005];
vector<int>node[100005];
int p,q;
int parrent[100005];
int dfs(int p)
{ 
     int cnt=1;

     dis[p]=1;
     vis[p]=1;
     for(auto i:node[p])
     {
        if(!vis[i])
          parrent[i]=p,cnt+=dfs(i);
     }

     dis[p]=cnt;

     return cnt;

}


int main()
{

       ios::sync_with_stdio(false);
       cin.tie(0);
       
    
           int n;
           cin>>n;
           
          int m=n-1;
          
          while(m--)
          {
             cin>>p>>q;
             node[p].push_back(q);
             node[q].push_back(p);
          }
 
           dfs(1);

           vector<pair<int,int>> v;

           for(int i=1;i<=n;i++)
              v.push_back({dis[i],i});
          
          vector<int>centroid;


           for(auto i:v)
           {
               int nod=i.s;
               int mx=0,sz=0;
               for(auto j:node[nod])
               {
                   if(parrent[j]==nod)
                     sz=dis[j];
                   else
                    sz=n-dis[nod];

                  mx=max(sz,mx);
               
               }

               if(mx<=n/2)
                centroid.push_back(nod);


           }
           
           cout<<"Print Centroid Of This Tree\n";
           
          for(auto i:centroid)
           cout<<i<<" ";
         
       

       
     
     return 0;
      
}

