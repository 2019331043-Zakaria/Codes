/*
* @Author: Zakaria 
* @Date:   2022-10-25 11:34:31
* @Last Modified time: 2022-10-25 11:46:59
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
const int N = 5e5+6;

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

ll fact1[N], fact2[N];

void Solve()
{
        
        int n, x;
        cin>>n>>x;

   

        ll a[n+1];

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i];

        
        fact1[0] = 1;
        fact2[0] = 1;
      
        ll mod1 = 1000001887, mod2 = 1000001957;

     
        for(int i=1 ; i<=x ; i++)
        {
            fact1[i] = (fact1[i-1]*i)%mod1;
            fact2[i] = (fact2[i-1]*i)%mod2;
        }

        ll sum1 = 0, sum2 = 0;

        for(int i=1 ; i<=n ; i++)
        {
        	sum1+=(fact1[a[i]]);
        	sum1%=mod1;
        	sum2+=fact2[a[i]];
        	sum2%=mod2;
        }

        sum1 = sum1 * bigmod(fact1[x], mod1-2, mod1);

        sum1%=mod1;

        sum2 = sum2 * bigmod(fact2[x], mod2-2, mod2);

        sum2%=mod2;

        if(sum2 == sum1)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;


      
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