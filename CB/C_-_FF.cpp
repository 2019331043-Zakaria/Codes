/*
* @Author: Zakaria 
* @Date:   2022-11-19 18:16:44
* @Last Modified time: 2022-11-19 18:20:30
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

void Solve()
{
        
       ll n, q;
       cin>>n>>q;

       map<ll, set<int> >m;

       for(int i=1 ; i<=q ; i++)
       {
       	  int type ;
       	  cin>>type ;
       	  if(type==1)
       	  {
       	  	ll a, b;
       	  	cin>>a>>b;
       	  	m[a].insert(b);
       	  }
       	  else if(type == 2)
       	  {
       	  	ll a, b;
       	  	cin>>a>>b;
       	  	auto it = m[a].find(b);
       	  	if(it==m[a].end())
       	  		continue;
       	  	else
       	  		m[a].erase(it);
       	  }
       	  else
       	  {
       	  	 ll a, b;
       	  	 cin>>a>>b;

       	  	 if(m[a].find(b)!=m[a].end() && m[b].find(a)!=m[b].end())
       	  	 {
       	  	 	cout<<"Yes"<<endl;
       	  	 }
       	  	 else
       	  	 	cout<<"No"<<endl;
       	  }
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