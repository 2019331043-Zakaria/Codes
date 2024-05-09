/*
* @Author: Zakaria 
* @Date:   2022-09-05 09:43:01
* @Last Modified time: 2022-09-05 09:48:39
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

const int N = 1e5+6, mod = 1e9+7;
ll a[N];

ll bigmod(ll a,ll b,ll n)
{
    ll res=1;
    a=a%n;
    if(a==0)
        return 0;
    while(b>0)
    {

            if(b%2)
            res=(res*a)%n;
            b=b/2;
            a=(a*a)%n;
    }
    return res;
}

void Solve()
{

        ll n, m, k;

        cin>>n>>m>>k;

        if(k==-1)
        {
            if(n%2 != m%2)
            {
                 cout<<0<<endl;
                 return ;
            }
        }

        ll pans=((n-1)%(mod-1) * ((m-1)%(mod-1)))%(mod-1);

        cout<<bigmod(2, pans, mod)<<endl;

}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 