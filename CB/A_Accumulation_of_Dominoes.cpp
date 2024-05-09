/*
* @Author: Zakaria 
* @Date:   2022-09-04 18:18:14
* @Last Modified time: 2022-09-04 18:18:14
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;

void Solve()
{
        
       ll n, m;
       cin>>n>>m;

       if(n==1 || m==1)
       {
         cout<<max(n,m)-1<<endl;
         return ;
       }

       cout<<n*(m-1)<<endl;
      
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