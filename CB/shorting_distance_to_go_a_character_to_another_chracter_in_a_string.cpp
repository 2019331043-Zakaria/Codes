#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define test     int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
vector<int>v[10];
int vis[100005],dis[100005];
vector<int>node[100005];

string s;

void bfs(int p)
{
    dis[p]=0;
    vis[p]=1;

    queue<int>q;
     q.push(p);


    while(!q.empty())
    {
        int temp=q.front();
        
        int tempn=s[temp]-'0';
        q.pop();
        
        for(auto i:v[tempn])
        {

            if(!vis[i])
            {
                vis[i]=1;
                q.push(i);
                dis[i]=dis[temp]+1;
            }        
    
        }
        v[tempn].clear();

       for(auto i:node[temp])
       {
           if(!vis[i])
           {
               dis[i]=dis[temp]+1;
               q.push(i);
               vis[i]=1;
           }


       }
        

    }

}


int main()
{      
      
        ios::sync_with_stdio(false);
        cin.tie(0);
        

         
       
        cin>>s;

        for(int i=0;i<s.size();i++)
            {
                v[s[i]-'0'].push_back(i);
                 
                 if(i+1<s.size())
                 {
                    node[i].push_back(i+1);
                    node[i+1].push_back(i);
                 }
                
            }
       
        bfs(0);

        cout<<dis[8];  
        
     return 0;
}
