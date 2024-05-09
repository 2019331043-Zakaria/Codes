/*
* @Author: Zakaria 
* @Date:   2022-12-13 03:02:14
* @Last Modified time: 2022-12-13 03:06:35
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
        int n, q;
        cin>>n>>q;

        ll frnds[n+1];
        ll pos[n+1];

        for(int i=1 ; i<=n ; i++)
        	frnds[i] = n+1;

        for(int i=1 ; i<=n ; i++)
        {
            int x;
            cin>>x;
            pos[x] = i;
        }


        while(q--)
        {
        	ll l, r;
        	cin>>l>>r;

        	l = pos[l];
        	r = pos[r];

        	if(r<l)
        		swap(l, r);

        	frnds[l] = min(frnds[l], r);
        }

        ll mn = n+1;

        ll ans = 0;

        for(int i=n ; i>=1 ; i--)
        {
           mn = min(mn, frnds[i]);
 
           ll temp = mn - 1;
 
           ll len = temp - i + 1;
           ans+=len;
        }

        cout<<ans<<endl;
      
      
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