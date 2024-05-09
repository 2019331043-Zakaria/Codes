/*
* @Author: Zakaria 
* @Date:   2022-11-26 20:08:02
* @Last Modified time: 2022-11-26 20:22:15
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

        ll G = 0;
        ll mx = 0;
        for(int i=1 ; i<=n ; i++)
        {
             ll x;
             cin>>x;
             mx = max(mx, x);
             G = GCD(x, G);
        }

        
       	cout<<mx/G<<endl;
        
      
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