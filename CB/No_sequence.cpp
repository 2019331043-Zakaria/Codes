/*
* @Author: Zakaria 
* @Date:   2023-01-05 13:32:55
* @Last Modified time: 2023-01-05 13:38:47
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
        
      ll n, k, s;
      cin>>n>>k>>s;

      vector<pair<int, ll> > v;

      ll temp = 1;

      for(int i=1 ;  ; i++)
      {
      	 if(i>n || temp>s)
      	 	break;

      	 v.push_back({i, temp});
      	 temp*=k;
      }

     /* cout<<v.size()<<endl;
      for(auto i:v)
      	cout<<i.f<<" "<<i.s<<endl;*/

      map<int, int > ans;
  
      while(v.size())
      {
      	 if(v.back().s<=s)
      	 {
      	 	ans[v.back().f] = 1;
      	 	s-=v.back().s; 
      	 }
      	 v.pop_back();
      }

      
      if(s)
      {
      	cout<<-2<<endl;
      	return ;
      }

      for(int i=1 ; i<=n ; i++)
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