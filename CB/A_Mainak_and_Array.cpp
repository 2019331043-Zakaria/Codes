/*
* @Author: Zakaria 
* @Date:   2022-10-02 10:10:20
* @Last Modified time: 2022-10-02 11:15:28
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

       int a[n];

       for(int i=0 ; i<n ; i++)
       	cin>>a[i];

       int ans=INT_MIN;

       for(int i=1 ; i<n ; i++)
       	ans=max(ans, a[i-1]-a[i]);

       ans=max(ans, a[n-1]-a[0]);

       
       int mn=INT_MAX;


       for(int i=0 ; i<n-1 ; i++)
       {
           mn=min(mn, a[i]);
           ans=max(ans, a[n-1]-mn);
       }
       int mx=INT_MIN;
       for(int i=n-1 ; i>=1 ; i--)
       {
           mx=max(mx, a[i]);
           ans=max(ans, mx-a[0]);
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