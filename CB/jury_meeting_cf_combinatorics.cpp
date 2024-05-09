#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         998244353
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002 

typedef long long ll;
using namespace std;


ll fact[MAX+4];
ll bigmod(ll b, ll p) 
{
    if(p == 0) return 1;
    ll h = bigmod(b, p/2);
    h = h * h % mod;
    if(p&1) h = h * b % mod;
    return h;
}
 
ll ncr(ll n, ll r) 
{
      if(n<r)
            return 0;
    return fact[n] * bigmod(fact[r] * fact[n-r] % mod, mod - 2) % mod;
}

void Fact()
{
    fact[0] = 1;
    for(ll i=1; i<=200002; i++) fact[i] = fact[i-1] * i % mod;
}


int main()
{
     
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      Fact();
      
      int tt;
      cin>>tt;
      while(tt--)
      {
              
              int n;
              cin>>n;
              ll a[n];
              for(int i=0 ;i<n ;i++)
              {
                  cin>>a[i];
              }

              sort(a,a+n);
              if(a[n-1]-a[n-2]>1)
                  cout<<0<<endl;
              else 
              {
                   if(a[n-1]==a[n-2])
                        cout<<fact[n]<<endl;
                   else
                   {
                       ll temp=0;
                       for(int i=0 ;i<n ;i++)
                        temp+=(a[i]==a[n-2]);
                       ll pans=n-temp-1;
                       ll ans=fact[n];

                        for(int i=0 ; i<=pans ;i++)
                        {
                            ll lans=fact[n-i-1];
                            lans*=fact[i];
                            lans%=mod;
                            lans*=ncr(pans,i);
                            lans%=mod;
                            ans-=lans;
                            ans=(ans+mod)%mod;
                        }
                        cout<<ans<<endl;
                   }
              }
             
      }       
return 0;           
              
}
