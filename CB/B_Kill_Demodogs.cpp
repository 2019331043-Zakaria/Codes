/*
* @Author: Zakaria 
* @Date:   2022-12-27 20:44:01
* @Last Modified time: 2022-12-27 22:41:38
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

      ll ans = 1;

      ans = ((n*(n+1)*(n+n+1))/3) - ((n*(n+1))/2);

      

      ll pans = n;
      pans*=(n+1);
      pans%=mod;
      pans*=(n+n+1);
      pans%=mod;
      pans*=333333336;
      pans%=mod;

      ll lans = n;
      lans*=(n+1);
      lans%=mod;
      lans*=500000004;
      lans%=mod;

      pans = pans - lans;
      pans+=mod;
      pans%=mod;

      pans*=2022;
      pans%=mod;

      cout<<pans<<endl;

      
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