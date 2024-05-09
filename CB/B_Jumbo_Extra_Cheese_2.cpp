/*
* @Author: Zakaria 
* @Date:   2022-10-29 15:13:37
* @Last Modified time: 2022-10-29 15:33:11
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

       ll a[n], b[n];
       
       ll mx1 = 0, mx2 = 0;

       for(int i=0 ; i<n ; i++)
       	cin>>a[i]>>b[i], mx1 = max(mx1, max(a[i], b[i]));


       ll ans1 = 2LL * mx1;

       for(int i=0 ; i<n ; i++)
       {
           ans1+=2LL*min(a[i], b[i]);
       }

       cout<<ans1<<endl;
      
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