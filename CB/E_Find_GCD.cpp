/*
* @Author: Zakaria 
* @Date:   2023-03-17 17:57:47
* @Last Modified time: 2023-03-18 01:02:29
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

const int mod = 1000000007;
const int N = 2e5+6;

ll bigmod(ll a,ll b,ll n)
{
    ll res=1;
    if(b==0)
        return 1;
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

ll fact[N];

void Solve()
{
        
        ll a, b, n;
        cin>>a>>b>>n;

        ll temp = min(a, b);

        

        if(temp==0)
        	temp = 1;

        cout<<bigmod(n, fact[temp], mod)<<endl;


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        

        ll temp = 1;
        fact[0] = 1;

        for(ll i=1 ; i<N ; i++)
        	fact[i] = fact[i-1]*i, fact[i]%=(mod-1);

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 