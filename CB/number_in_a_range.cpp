/*
* @Author: Zakaria 
* @Date:   2022-06-03 03:49:18
* @Last Modified time: 2022-06-03 03:49:30
*/
/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-03 03:39:16
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


ll a[200005],b[200005];
int main()
{
 
      
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];

      sort(a,a+n);
      
      int q;
      cin>>q;
      int x,y;
      while(q--)
      {
         cin>>x>>y;
         int low1=lower_bound(a,a+n,x)-a;
         int low2=upper_bound(a,a+n,y)-a;
         cout<<low2-low1<<" ";

      } 

     return 0;           
              
}