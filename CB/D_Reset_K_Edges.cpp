/*
* @Author: Zakaria 
* @Date:   2022-09-30 14:08:44
* @Last Modified time: 2022-10-01 15:20:09
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

int dis[N], subtree[N];
int n, k;
vector<int> node[N];
int op;
int len;

void dfs(int p, int parent)
{
	   dis[p]=0;
	   for(auto i:node[p])
	   {
	   	  if(i!=parent)
	   	  {
	   	  	 dfs(i, p);
                         dis[p]=max(dis[p], dis[i]+1);
	   	  }
	   }

           if(dis[p]+1 == len && parent>1)
           {
                op++;
                dis[p]=-1;
           }

      	   
}

bool Check(int mid)
{
 
        
        op=0;
        len=mid;
        dfs(1, 0);
        return op<=k;
}

void Solve()
{
        
        cin>>n>>k;

        for(int i=1 ; i<=n ; i++)
        {
        	dis[i]=0;
        	node[i].clear();
        	
        }

        for(int i=2 ; i<=n ; i++)
        {
        	int x;
        	cin>>x;
        	node[i].push_back(x);
        	node[x].push_back(i);
        }

        

        int low=1, high=n-1;
        int ans=n-1;
        while(low<=high)
        {
        
        	for(int i=1 ; i<=n ; i++)
        	dis[i]=0;

        	int mid=(low+high)/2;
           
        	if(Check(mid))
                ans=mid, high=mid-1;
                else
            	low=mid+1;
        }

        cout<<ans<<endl;
      
      
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