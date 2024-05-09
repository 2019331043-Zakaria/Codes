/*
* @Author: Zakaria 
* @Date:   2022-10-08 18:02:30
* @Last Modified time: 2022-10-08 18:06:58
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
        
       int n, m;
       cin>>n>>m;

       for(int i=1 ; i<=m ; i++)
       {
       	  int k;
       	  cin>>k;
       	  while(k--)
       	  {
       	  	 int x;
       	  	 cin>>x;
       	  	 node[x].push_back(i);
       	  }
       }

       for(int i=1 ; i<=n ; i++)
       {
       	  map<int, int>mp;
       	  for(auto j:node[i])
       	  	mp[j]++;

       	  for(int j=i+1 ; j<=n ; j++)
       	  {
       	  	   bool ok=0;

                for(auto k:node[j])
                {
                	 if(mp[k]==1)
                	 	ok=1;
                }

                if(!ok)
                {
                	cout<<"No"<<endl;
                	return ;
                }
       	  }

       }

       cout<<"Yes"<<endl;


      
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