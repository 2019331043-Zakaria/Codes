/*
* @Author: Zakaria 
* @Date:   2023-01-25 20:39:54
* @Last Modified time: 2023-01-25 20:44:18
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

      ll a[n];

      ll sum = 0;

      for(int i=0 ; i<n ; i++)
      {
      	 cin>>a[i];
      	 sum+=a[i];
      }

      ll ans = 1;
      
      ll left = 0;

      for(auto i:a)
      {
      	 left+=i;
      	 sum-=i;

      	 if(left && sum)
      	 {
      	 	ans = max(ans, GCD(left, sum));
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