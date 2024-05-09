/*
* @Author: Zakaria 
* @Date:   2022-10-13 20:44:16
* @Last Modified time: 2022-10-13 20:48:33
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

void Solve()
{
        
        int n;
        cin>>n;

        for(int i=1; i<=10000 ; i++)
        	node[i].clear();


        for(int i=1 ; i<=n ; i++)
        {
        	 int x;
        	 cin>>x;
        	 node[x].push_back(i);
        }

        int ans=0;

        for(int i=1 ; i<=1000 ; i++)
        {
        	if(node[i].size()==0)
        		continue;

        	int mx=0;
        	bool ok=0;

        	for(int j=1 ; j<=1000 ; j++)
        	{
        		if(node[j].size()==0)
        			continue;

        		if(GCD(i, j)==1)
        		{
        		   ok=1;
                   mx=max(mx, node[j].back());
        		}
        	}
            if(ok)
        	ans=max(ans, mx+node[i].back());
        }
        if(ans)
        cout<<ans<<endl;
        else
        	cout<<-1<<endl;

      
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