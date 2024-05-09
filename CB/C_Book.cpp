/*
* @Author: Zakaria 
* @Date:   2022-10-03 18:54:51
* @Last Modified time: 2022-10-03 19:11:10
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
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int mod = 1e9+7;
const int N = 2e5+6;

vector<int>node[N];
int vis[N];
int in[N];
int ans[N];

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

void Solve()
{
       
         int n;
         cin>>n;

         for(int i=1 ; i<=n ; i++)
         	node[i].clear(), vis[i]=0, in[i]=0, ans[i]=0;

         for(int i=1 ; i<=n  ; i++)
         {
         	   int k;
         	   cin>>k;
         	   for(int j=1 ; j<=k ; j++)
         	   {
         	   	   int x;
         	   	   cin>>x;
         	   	   node[x].push_back(i);
         	   	   in[i]++;
         	   }
         } 


         for(int i=1;i<=n;i++)
	     {
	     	 if(!vis[i])
	     	 {
	     	 	if(dfs(i))
	     	 	{
	     	 		 cout<<-1<<endl;
	     	 		 return ;
	     	 	}
	     	 }
	     }

	     queue<int>q;

	     for(int i=1 ; i<=n ; i++)
	     	if(in[i]==0)
	     		q.push(i), ans[i]=1;

	     

	     while(q.size())
	     {
	     	 int p=q.front();
	     	 q.pop();

	     	 for(auto i:node[p])
	     	 {
	     	 	 if(i<p)
	     	 	 	ans[i]=max(ans[i], 1 + ans[p]);
	     	 	 else
	     	 	 	ans[i]=max(ans[i], ans[p]);
                 
                 in[i]--;
                 if(in[i]==0)
                 	q.push(i);
	     	     	 
	     	 }
	     }
         
         int res=0;
         for(int i=1 ; i<=n ; i++) res=max(res, ans[i]);

         cout<<res<<endl;




         

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 