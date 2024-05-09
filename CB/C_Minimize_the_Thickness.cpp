/*
* @Author: Zakaria 
* @Date:   2022-10-11 20:54:43
* @Last Modified time: 2022-10-11 21:05:39
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

        ll a[n+1];
        ll cum[n+1];
        cum[0]=0;

        ll sum=0;

        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	sum+=a[i];
        	cum[i]=sum;
        }
        
        int ans=n;

        for(int i=1 ; i<=n ; i++)
        {
              ll sum=cum[i];
              ll temp=0;
              int res=i;
              int thick=0;
              for(int j=i+1 ; j<=n ; j++)
              {
                  temp+=a[j];
                  thick++;
                  if(temp==sum)
                  {
                  	res=max(res, thick);
                    thick=0;
                  	temp=0;
                  }
              }

              if(temp==0)
              	ans=min(ans, res);
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