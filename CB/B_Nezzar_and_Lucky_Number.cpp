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

const int N = 1e5+6;

bool Ok(ll x, ll d)
{
      while(x>=d)
      {
          ll temp=x;
          while (temp)
          {
             if(temp%10==d)
             {
                 return 1;
             }
             temp/=10;
          }
          x-=d;

      }

      return 0;
}
void Solve()
{
        cout<<"Hell";
        
      
      
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