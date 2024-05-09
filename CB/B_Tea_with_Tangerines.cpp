/*
* @Author: Zakaria 
* @Date:   2022-10-02 21:13:07
* @Last Modified time: 2022-10-02 21:16:18
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
       ll a[n];

       for(int i=0 ; i<n ; i++)
       	cin>>a[i];

       sort(a, a+n);

       ll ans=0;

       for(int i=1 ; i<n ; i++)
       {
       	   
       	   	   ll temp=2*a[0]-1;

       	   	   ans+=(a[i]+temp-1)/temp - 1;
       	   
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