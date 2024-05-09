/*
* @Author: Zakaria 
* @Date:   2022-12-01 19:54:39
* @Last Modified time: 2022-12-02 14:05:27
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

ll a[N], b[N];
int n;

int Check(ll x)
{
	  for(int i=1 ; i<=n ; i++)
	  {
	  	 if(b[i]==1)
	  	 {
	  	 	if(x<1900)
	  	 		return 1;
	  	 	x+=a[i];
	  	 }
	  	 else
	  	 {
	  	 	if(x>=1900)
	  	 		return -1;
	  	 	x+=a[i];
	  	 }
	  }

	  return 0;
}

void Solve()
{
        
      cin>>n;
      ll delta = 0;

      for(int i=1 ; i<=n ; i++)
      {
      	  cin>>a[i]>>b[i];
      	  delta+=a[i];
      }  


      ll low = -1e9, high = 1e9;
      ll ans = -1e18;

      while(low<=high)
      {
              ll mid = (low+high)/2;

              int ok = Check(mid);

              if(ok==0)
              {
                ans = mid;
                low = mid+1;
              }
              else if(ok==-1)
              {
                  high = mid - 1;
              }
              else if(ok==1)
              {
                  low = mid + 1;
              }
      }

      if(ans==-1e18)
        cout<<"Impossible"<<endl;
      else if(ans==1e9)
        cout<<"Infinity"<<endl;
      else
        cout<<ans + delta<<endl;
} 
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 