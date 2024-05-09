/*
* @Author: Zakaria 
* @Date:   2022-09-13 20:53:55
* @Last Modified time: 2022-09-13 22:00:03
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

ll colorcost[N][4];
vector<int>node[N];
vector<int>path;

void dfs(int  p, int parent)
{
	  path.push_back(p);

	  for(auto i:node[p])
	  {
	  	  if(i!=parent)
	  	  	dfs(i, p);
	  }
}

void Solve()
{
        
        int n;
        cin>>n;

        for(int i=1 ; i<=n ; i++)
        	cin>>colorcost[i][1];
        
        for(int i=1 ; i<=n ; i++)
        	cin>>colorcost[i][2];

        for(int i=1 ; i<=n ; i++)
        	cin>>colorcost[i][3];

        for(int i=1 ; i<n ; i++)
        {
        	int x, y;
        	cin>>x>>y;
        	node[x].push_back(y);
        	node[y].push_back(x);
        }
        
        int root=1;

        for(int i=1 ; i<=n ; i++)
        {
        	if(node[i].size()>=3)
        	{
        		 cout<<-1<<endl;
        		 return ;
        	}
        	if(node[i].size()==1)
        		root=i;
        }

        dfs(root, 0);


        vector<int>permutation;
        permutation.push_back(1);
        permutation.push_back(2);
        permutation.push_back(3);

        ll ans=LLONG_MAX;
        

        do{

        	ll res=0;
        	for(int i=0 ; i<path.size() ; i++)
        	 res+=colorcost[path[i]][permutation[i%3]];

        	ans=min(res, ans);
               
        }while(next_permutation(permutation.begin(), permutation.end()));


        cout<<ans<<endl;

        ll pans[n+1];

        do{

        	ll res=0;
        	for(int i=0 ; i<path.size() ; i++)
        	 res+=colorcost[path[i]][permutation[i%3]];

            if(res==ans)
            {
            	for(int i=0 ; i<path.size() ; i++)
            		pans[path[i]]=permutation[i%3];
            	
            	for(int i=1 ; i<=n ; i++)
            		cout<<pans[i]<<" ";
            	cout<<endl;
            	return;
            }	
               
        }while(next_permutation(permutation.begin(), permutation.end()));

   
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