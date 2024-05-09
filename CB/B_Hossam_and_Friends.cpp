/*
* @Author: Zakaria 
* @Date:   2022-12-11 21:40:23
* @Last Modified time: 2022-12-11 22:00:41
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
        
       int n, m;
       cin>>n>>m;

       ll frnds[n+1];

       for(int i=1 ; i<=n ; i++)
       	frnds[i] = n+1;

       vector<pair<int, int> > v;

       for(int i=1 ; i<=m ; i++)
       {
       	  ll x, y;
       	  cin>>x>>y;

       	  v.push_back({x, y});

       	  if(x>y)
       	  	swap(x, y);

       	  frnds[x] = min(frnds[x], y);
       }

     

       ll mn = n+1;

       ll ans = 0;

       for(int i=n ; i>=1 ; i--)
       {
           mn = min(mn, frnds[i]);

           ll temp = mn - 1;

           ll len = temp - i + 1;

           //cout<<len<<endl;

           ans+=len;
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