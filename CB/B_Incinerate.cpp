/*
* @Author: Zakaria 
* @Date:   2022-12-20 18:01:39
* @Last Modified time: 2022-12-20 18:16:11
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
        
      ll n, k;
      cin>>n>>k;

      ll a[n+1], p[n+1];

      for(int i=1 ; i<=n ; i++)
      	cin>>a[i];

      for(int i=1 ; i<=n ; i++)
      	cin>>p[i];

      set<pair<int, int> > health, power;

      for(int i = 1 ; i<=n ; i++)
      {
      	 health.insert({a[i], i});
      	 power.insert({p[i], i});
      }

      ll cur = 0, h = k;

      while(health.size())
      {
          
       	  while(health.size())
       	  {
	       	   auto it = *health.begin();

	       	   if(cur + h>=it.f)
	       	   {
	               int temp = it.s;
	               health.erase(health.begin());
	               power.erase({p[temp], temp});
	       	   }
	       	   else
	       	   {
	               break;
	       	   }
       	   }
           
           if(health.size()==0)
           {
           	  break;
           }

           cur+=h;
           auto it = *power.begin();
           h-=it.f;

           if(h<=0)
           	break;
      }
      
      if(health.size())
      	cout<<"NO"<<endl;
      else
      	cout<<"YES"<<endl;
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