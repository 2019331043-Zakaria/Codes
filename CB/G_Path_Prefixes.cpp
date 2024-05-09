/*
* @Author: Zakaria 
* @Date:   2022-09-28 09:58:06
* @Last Modified time: 2022-09-28 10:34:29
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
ll a[N], b[N], ans[N], dis[N];
int n;
vector<ll>cost;

int upperIndex(vector<ll>& arr, int n, ll y)
{
	   int l = 0, h = n - 1;
	   while (l <= h) {
	      int mid = (l + h) / 2;
	      if (arr[mid] <= y)
	         l = mid + 1;
	      else
	         h = mid - 1;
	   }
	   return h;
}

void dfs(int par, int parent, ll sumA, ll sumB)
{
	  
	  
      sumA+=a[par];
      sumB+=b[par];
      
      cost.push_back(sumB);
            
      ans[par]=upperIndex(cost, cost.size(), sumA);

	  for(auto i:node[par])
	  {
	  	  if(i!=parent)
	  	  	dfs(i, par, sumA, sumB);
	  }

	  cost.pop_back();

}

void Solve()
{
        
        cin>>n;

        for(int i=1; i<=n ; i++)
        	node[i].clear(), a[i]=0, b[i]=0, dis[i]=0;

        cost.clear();

        for(int i=2 ; i<=n ; i++)
        {
        	   int p, x, y;
        	   cin>>p>>x>>y;
               
        	   node[p].push_back(i);
        	   node[i].push_back(p);
        	   a[i]=x;
        	   b[i]=y;
        }     
         
      
        dfs(1, 0, 0, 0);   

        for(int i=2 ; i<=n ; i++)
        	cout<<ans[i]<<" ";
        cout<<endl;

        
      
      
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