/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-03 03:40:37
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
#define  MAX         1000002
typedef long long ll;
using namespace std;

int n, m;
ll a[MAX];
ll cum[MAX];
ll l, r, x;
vector<int>v[MAX];

bool check(int pos)
{
            
           
            ll sum = cum[pos] - cum[l-1];

            ll dis = pos-l+1;
            
            ll low=lower_bound(v[x].begin(), v[x].end(), l)-v[x].begin();
            ll up=upper_bound(v[x].begin(), v[x].end(), pos)- v[x].begin();

            if(sum==x*dis && up-low==dis)
                return 0;
            else
               return 1; 


}

void Solve()
{  
         
          cin>>n>>m;

          for(int i=1 ; i<=n ; i++)
          {
              cin>>a[i];
              v[a[i]].push_back(i);
              cum[i]=cum[i-1]+a[i];
          }

          while(m--)
          {
            
                  
                  cin>>l>>r>>x;
                  
                  ll low=l, high=r, mid;
                  ll ans=n+1;

                  while(low<=high)
                  {
                      ll mid=(low+high)/2;
                     
                      if(check(mid))
                        high=mid-1, ans=min(ans, mid);
                      else
                        low=mid+1;
                  }

                  if(ans==n+1)
                  {
                      cout<<-1<<endl;
                  }
                  else
                    cout<<ans<<endl;
          }


         
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
      //    cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}