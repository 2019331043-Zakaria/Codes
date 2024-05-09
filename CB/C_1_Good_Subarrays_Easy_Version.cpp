/*
* @Author: Zakaria 
* @Date:   2022-10-10 20:50:11
* @Last Modified time: 2022-10-10 21:36:16
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

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        ll temp[n+1];
        ll cnt=0;

        for(int i=1 ; i<=n ; i++)
        {
           if(cnt>a[i])
           	temp[i]=a[i], cnt=a[i];
           else
           {
           	   ll pans = min(cnt+1, a[i]);
           	   temp[i]=pans;
           	   cnt=pans;
           }
        }

        

        ll ans=0;
        
        for(int i=1 ; i<=n ; i++)
        {
            ans+=(temp[i]*(temp[i]+1))/2;
            ll pans=temp[i]-1;
            ans-=(pans*(pans+1))/2;
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