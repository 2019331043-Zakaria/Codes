/*
* @Author: Zakaria 
* @Date:   2023-03-19 21:11:32
* @Last Modified time: 2023-03-19 21:15:31
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
        
      int n,q;
      cin>>n>>q;

      ll a[n+1];
      ll sum[n+1];
      sum[0] = 0;

      for(int i=1 ; i<=n ; i++)
      {
      	cin>>a[i];
      	sum[i] = sum[i-1] + a[i];
      }


      while(q--)
      {
      	 ll l, r, k;
      	 cin>>l>>r>>k;

      	 ll tot = sum[n];
      	 ll temp = sum[r] - sum[l-1];
      	 tot-=temp;
      	 tot+=(r-l+1)*k;

      	 if(tot%2)
      	 	cout<<"YES"<<endl;
      	 else
      	 	cout<<"NO"<<endl;
      }


      
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