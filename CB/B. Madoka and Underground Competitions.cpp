/*
* @Author: Zakaria 
* @Date:   2022-09-04 00:27:09
* @Last Modified time: 2022-09-04 11:31:31
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

void Solve()
{
      int n, m;
      cin>>n>>m;

      ll a[n+1];
      a[0]=0;

      for(int i=1 ; i<=n ; i++) cin>>a[i];

      ll cum=0;

      ll sum=0;

      ll ans=-1e17;

      for(int i=1 ; i<=n ; i++)
      {
           
        if(i<m)
        {
          cum+=(i*a[i]);
          sum+=a[i];
        }
        else if(i==m)
        {        
                 cum+=i*a[i];
                 sum+=a[i];
                 ans=max(ans, cum);
        }
        else
        {
        
              cum-=a[i-m];
              sum-=a[i-m];
              cum-=sum;
            
              cum+=(m*a[i]);
              ans=max(ans, cum);

              sum+=a[i];
              
        }
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