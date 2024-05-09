/*
* @Author: Zakaria 
* @Date:   2022-10-07 15:07:59
* @Last Modified time: 2022-10-07 15:17:12
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

int subsize[N], timer[N], check[N];
vector<int>node[N];
int t;

int dfs(int p, int par)
{ 
        check[t]=p;
        timer[p]=t++;

        int cur=1;

        for(auto i:node[p])
        {
        	if(i!=par)
        	{
        		cur+=dfs(i, p);
        	}
        }
        return subsize[p]=cur;

}
void Solve()
{
        
        int n, q;
        cin>>n>>q;

        for(int i=2 ; i<=n ; i++)
        {
        	int x;
        	cin>>x;
        	node[x].push_back(i);
        }

        dfs(1, 0);

        while(q--)
        {
        	  int p, k;
        	  cin>>p>>k;
        	  if(subsize[p]<k)
        	  	cout<<-1<<endl;
        	  else
        	  	cout<<check[timer[p]+k-1]<<endl;
        }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 