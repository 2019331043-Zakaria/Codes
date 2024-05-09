/*
* @Author: Zakaria 
* @Date:   2023-02-27 21:00:53
* @Last Modified time: 2023-02-27 22:02:31
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
        
      int n;
      cin>>n;

      ll a[n];

      vector<pair<ll , ll> > v;
      for(int i=0 ; i<n ; i++)
      	cin>>a[i], v.push_back({a[i], i+1});

      sort(v.begin(), v.end());

      map<int, int>index;

      for(int i=0 ; i<n ; i++)
      {
      	 index[i] = v[i].s;
      }


      sort(a, a+n);

      if(a[0]==a[n-1])
      {
      	 cout<<0<<endl;
      	 return ;
      }

      if(a[0]==1 && a[n-1]!=1)
      {
      	 cout<<-1<<endl;
      	 return ;
      }


      //make minimum;

      vector<pair<int ,int> > ans;
      // bool ok = 1;
      // for(int i=1 ; i<n ; i++)
      // {
      // 	 ll pans = a[i];
      // 	 while(pans%a[0]==0 && pans>a[0])
      // 	 {
      // 	 	pans/=a[0];
      // 	 	ans.push_back({index[i], index[0]});
      // 	 }

      // 	 if(pans!=a[0])
      // 	 	ok = 0;
      // }

      // if(ok)
      // {
      // 	  cout<<ans.size()<<endl;
      // 	  for(auto i:ans)
      // 	  	cout<<i.f<<" "<<i.s<<endl;
      // 	  return ;
      // }

      // ans.clear();



      while(1)
      {
           
            // for(auto i:v)
            // 	cout<<i.f<<" "<<i.s<<endl;
            sort(v.begin(), v.end());

            // cout<<"after "<<endl;

            // for(auto i:v)
            // 	cout<<i.f<<" "<<i.s<<endl;
            
            if(v[0].f==v[n-1].f)
            {
            	break;
            }
            if(v[0].f==1 && v[n-1].f!=1)
            {
            	cout<<-1<<endl;
            	return ;
            }

            for(int i=1; i<n ; i++)
            {
            	if(v[i].f==v[0].f)
            		continue;
            	ans.push_back({v[i].s, v[0].s});
            	v[i].f = (v[i].f+v[0].f-1)/v[0].f;
            }

      }

      cout<<ans.size()<<endl;
      for(auto i:ans)
      	cout<<i.f<<" "<<i.s<<endl;


      
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