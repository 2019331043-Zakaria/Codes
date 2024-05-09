/*
* @Author: Zakaria 
* @Date:   2022-10-29 15:35:15
* @Last Modified time: 2022-10-30 10:30:49
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
       
       for(int i=0 ; i<n ; i++)
        cin>>a[i];
       

       sort(a, a+n);

       ll ans = 0;

       for(int i=0 ; i<n-2 ; i++)
       {
           ans = max(ans, a[n-1] - a[i] + a[i+1] - a[i]);
       }

       for(int i=n-1 ; i>1 ; i--)
       {
           ans = max(ans, a[i] - a[i-1] + a[i] - a[0]);
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