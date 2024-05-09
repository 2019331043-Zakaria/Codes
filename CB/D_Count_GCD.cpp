/*
* @Author: Zakaria 
* @Date:   2022-11-06 22:45:41
* @Last Modified time: 2022-11-09 20:15:06
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

const int mod = 998244353;
const int N = 2e5+6;

set<long long> fact(long long n) {
    set<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}

void Solve()
{
        
        
        ll n, m;
        cin>>n>>m;

        ll a[n+1];

        for(int i=1 ; i<=n ; i++)
        {
            cin>>a[i];
        }


        ll ans = 1;

        for(int i=2 ; i<=n ; i++)
        {
            if(a[i-1]%a[i])
            {
                cout<<0<<endl;
                return ;
            }

            if(a[i-1] == a[i])
                ans*=(m/a[i]), ans%=mod;
            else
            {
                set<ll>offset = fact(a[i-1] / a[i]);
                vector<ll>primes;

                for(auto i:offset)
                    primes.push_back(i);

                ll total = m/a[i];

                ll res = total;

                int sz = primes.size();

             
                  for(int mask=1 ; mask < (1LL<<sz) ; mask++)
                  {
                         
                         ll temp=1;
                         int cnt=0;
                         for(int i=0 ; i<sz ; i++)
                         {
                             if(mask&(1LL<<i))
                                temp *= primes[i], cnt++;
                         }
         
                         ll cur = total/temp;
                         
                         if(cnt%2)    //subset size
                          res-=cur;
                         else        // inclusion exclusion 
                          res+=cur;
                  }
                res%=mod;
                ans*=res;
                ans%=mod;
            }
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