/*
* @Author: Zakaria 
* @Date:   2023-03-23 20:42:13
* @Last Modified time: 2023-03-23 21:34:28
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
        
      ll n;
      cin>>n;

      
      
      ll low = 0, high = 1e9;

      ll ans = high;

      while(low<=high)
      {
      	   ll mid = (low+high)/2;

      	   ll col = mid  + 1;

      	   ll row = mid + 1;

      	   ll tot = col*row;

      	   if(tot>=n)
      	   {
      	   	  ans = mid;
      	   	  high = mid - 1;
      	   }
      	   else
      	   	low = mid + 1;
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