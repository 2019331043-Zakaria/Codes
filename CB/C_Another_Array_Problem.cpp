/*
* @Author: Zakaria 
* @Date:   2022-12-21 12:04:44
* @Last Modified time: 2022-12-21 12:19:24
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

       ll a[n+1];
       ll mx = 0;

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i], mx = max(mx, a[i]);

       if(n==2)
       {
       	  cout<<max(a[1]+a[2], abs(a[1] - a[2])*2LL)<<endl;
       	  
       }
       else if(n==3)
       {
            ll sum = 0;
            sum = max(sum, a[1]+a[2]+a[3]);
            sum = max(sum, a[1] + 2*abs(a[2] - a[3]));
            sum = max(sum, 3*abs(a[1] - a[3]));
            sum = max(sum, a[3] + 2*abs(a[1] - a[2]));

            ll x = abs(a[1] - a[2]);
            sum = max(sum, x + 2*abs(x - a[3]));
            sum = max(sum, 3*abs(x - a[3]));

            x = abs(a[2] - a[3]);

            sum = max(sum, 2*abs(a[1] - x) + x);
            sum = max(sum, 3*abs(x - a[1]));

            sum = max(sum, 3*a[1]);
            sum = max(sum, 3*a[3]);

            sum = max(sum, 3*abs(a[1] - a[2]));
            sum = max(sum, 3*abs(a[2] - a[3]));
            sum = max(sum, 3*abs(a[1] - a[3]));


            cout<<sum<<endl;
       }
       else
       {
       	  cout<<n*mx<<endl;
       }
      
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