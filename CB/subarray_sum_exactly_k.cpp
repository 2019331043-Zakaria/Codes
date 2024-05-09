/*
* @Author: Zakaria 
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-08-08 12:49:51
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002
#define  sz          500005
typedef long long ll;
using namespace std;


void Solve()
{
      

      ll n, k;
      cin>>n>>k;
      map<ll,ll>m;
      ll ans=0;
      ll cum=0;

      for(int i=0 ; i<n ; i++)
      {
            ll x;
            cin>>x;
            cum+=x;
            if(cum==k)
                  ans++;
            ans+=m[cum-k];
            m[cum]++;
      }
      cout<<ans<<endl;
       
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