/*
* @Author: Zakaria 
* @Date:   2022-12-16 20:42:22
* @Last Modified time: 2022-12-16 20:48:27
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

      for(int i=0 ; i<n ; i++)
      	cin>>a[i];

      ll temp = a[0];

      sort(a, a+n);

      ll ans = 0;

      for(auto i:a)
      {
      	  if(i>=temp)
      	  {
      	  	 ll pans = i - temp;

      	  	 temp+=(pans+1)/2;
      	  }
      }
      
      cout<<temp<<endl;
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