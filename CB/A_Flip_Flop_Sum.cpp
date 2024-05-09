/*
* @Author: Zakaria 
* @Date:   2023-02-01 20:35:25
* @Last Modified time: 2023-02-01 20:39:20
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

      int sum = 0;

      int a[n+1];

      for(int i=1 ; i<=n ;  i++)
      {
      	 int x;
      	 cin>>x;
      	 a[i] = x;

      	 sum+=x;
      	
      }

      int ans = INT_MIN;

      for(int i=1 ; i<n ; i++)
      {
      	  int ok = a[i];
      	  int dk = a[i+1];

      	  ok*=-1;
      	  dk*=-1;

      	  ans = max(ans, sum-a[i]-a[i+1]+ok+dk);
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