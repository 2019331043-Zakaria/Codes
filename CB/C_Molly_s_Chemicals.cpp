/*
* @Author: Zakaria 
* @Date:   2022-12-05 17:19:07
* @Last Modified time: 2022-12-05 17:31:48
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

        ll a[n];
        for(int i=0 ; i<n ; i++)
        	cin>>a[i];

        if(abs(k)<=1)
        {
              map<ll,ll>m;
		      ll ans=0;
		      ll cum=0;

		      for(int i=0 ; i<n ; i++)
		      {
		            ll x;
		            x = a[i];
		            cum+=x;
		            if(cum==k)
		                  ans++;
		            ans+=m[cum-k];
		            m[cum]++;
		      }
              
              if(k>=0)
              {
              	cout<<ans<<endl;
              	return ;
              }

		      k*=k;
		      m.clear();
		      cum=0;

		      for(int i=0 ; i<n ; i++)
		      {
		            ll x;
		            x = a[i];
		            cum+=x;
		            if(cum==k)
		                  ans++;
		            ans+=m[cum-k];
		            m[cum]++;
		      }
		      cout<<ans<<endl;


		      return ;
        }

        ll ans=0;
        
        ll temp = 1;

        while(abs(temp)<=1e18)
        {
        	  map<ll,ll>m;
		      ll cum=0;

		      for(int i=0 ; i<n ; i++)
		      {
		            ll x;
		            x = a[i];
		            cum+=x;
		            if(cum==temp)
		                  ans++;
		            ans+=m[cum-temp];
		            m[cum]++;
		      }
		      temp*=k;
        }

        cout<<ans<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 