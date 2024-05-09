/*
* @Author: Zakaria 
* @Date:   2022-11-05 18:01:37
* @Last Modified time: 2022-11-05 18:03:24
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

set<int>node[N];

void Solve()
{
        
        int n , m;
        cin>>n>>m;

        for(int i=1 ; i<=m ; i++)
        {
        	int x, y;
        	cin>>x>>y;
        	node[x].insert(y);
        	node[y].insert(x);
        }

        for(int i=1 ; i<=n ; i++)
        {
        	cout<<node[i].size()<<" ";

        	for(auto k:node[i])
        		cout<<k<<" ";
        	cout<<endl;
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