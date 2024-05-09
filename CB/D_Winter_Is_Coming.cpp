/*
* @Author: Zakaria 
* @Date:   2022-09-24 15:16:47
* @Last Modified time: 2022-09-24 16:23:47
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
        
         int n, k;
         cin>>n>>k;

         int sum=0, cnt=0;
         int ok=1;

         int ans=0;

         for(int i=1 ; i<=n ; i++)
         {
              int x;
              cin>>x;
              
              if(cnt==k)
              {
                 ans++;
                 ok=1;
                 sum=0;
               /*  sum+=x;
                 if(sum>=0)
                 	ans++;
*/
                 cnt=0;
              }

              if(ok)
              {
                   if(sum+x>=0)
                   {
                      sum+=x;
                   }
                   else
                   {

                       ans++;
                       sum=x;
                       cnt=1;
                       ok=0;
                       
                   }
              }
              else
              {
                   sum+=x;
                   cnt++;

              }
              cout<<ans<<endl;

              
         }

         cout<<ans<<endl;
      
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 