/*
* @Author: Zakaria 
* @Date:   2022-09-21 17:22:46
* @Last Modified time: 2022-09-21 18:50:21
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
ll ans;
ll cost[N];
ll add[N], sub[N];


void  dfs(int p, int par)
{
	   ll tempadd=0, tempsub=0;

       for(auto i:node[p])
       {
			if(i==par)
				continue;

			dfs(i, p);
			tempadd=max(tempadd, add[i]);
			tempsub=max(tempsub, sub[i]);
       }
       

       cost[p]+=(tempadd - tempsub);
       
       add[p]=tempadd;
       sub[p]=tempsub;

       if(cost[p]>0)
       	sub[p]+=abs(cost[p]);
       else
       	add[p]+=abs(cost[p]);

}

void Solve()
{
        
       int n;
       cin>>n;

       for(int i=1 ; i<n ; i++)
       {
       	   int x, y;
       	   cin>>x>>y;
       	   node[x].push_back(y);
       	   node[y].push_back(x);
       }      

       for(int i=1 ; i<=n ; i++)
       	cin>>cost[i];

       dfs(1, -1);
       cout<<sub[1]+add[1]<<endl;
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