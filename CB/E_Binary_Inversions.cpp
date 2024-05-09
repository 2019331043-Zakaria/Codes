/*
* @Author: Zakaria 
* @Date:   2022-11-21 20:44:41
* @Last Modified time: 2022-11-21 20:57:52
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

        int a[n+1];
        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        ll cum[n+1];
        
        cum[0] = 0;

        ll inv[n+1];

        for(int i=1 ; i<=n ; i++)
        {
        	cum[i] = cum[i-1];

        	if(a[i]==0)
        		cum[i]++;
        }

        inv[0] = 0;

        for(int i=1 ; i<=n ; i++)
        {
        	inv[i] = inv[i-1];

        	if(a[i]==1)
        		inv[i]+=(cum[n] - cum[i-1]);

        }

      

        ll ans = inv[n];
        ll one = 0;

        for(int i=1 ; i<=n ; i++)
        {
            if(a[i]==1)
            {
            	  ll temp = inv[n] - (cum[n] - cum[i-1]);
            	  temp+=one;
            	  ans = max(ans, temp);
            	  one++;
            }
            else
            {
                  ll temp = inv[n] - one;
                  temp+=(cum[n] - cum[i]);
                  ans = max(ans, temp);
            }
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