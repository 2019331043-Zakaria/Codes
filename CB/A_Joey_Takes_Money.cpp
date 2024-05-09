/*
* @Author: Zakaria 
* @Date:   2022-12-27 20:35:33
* @Last Modified time: 2022-12-27 20:41:25
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

       for(int i=1 ; i<=n ; i++)
       {
       	   ll x;
       	   cin>>x;
       	   ans*=x;
       }

       ll res = 0;

       for(ll i=1 ; i*i<=ans ; i++)
       {
       	   if(ans%i==0)
       	   {
               res = max(res, )
       	   }
       }

      

     

       cout<<ans*20222LL<<endl;
      
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