/*
* @Author: Zakaria 
* @Date:   2022-11-26 20:23:31
* @Last Modified time: 2022-11-26 21:04:13
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
        
        ll n;
        cin>>n;

        map<ll, ll>m;

        ll a[n+1];

        set<ll>st;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i], m[a[i]]++, st.insert(a[i]);
        
       ll ans = 0;

       if(st.size()==1)
       {
       	  cout<<n/2<<endl;
       	  return ;
       }
       
       ll tot = n;
       ll cur = 0;

       for(auto i:st)
       {
          cur+=m[i];
          tot-=m[i];

          ans = max(ans, cur*tot);
       }

       cout<<ans<<endl;
       
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