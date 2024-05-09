/*
* @Author: Zakaria 
* @Date:   2023-02-05 18:25:55
* @Last Modified time: 2023-02-05 18:37:19
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

ll a[N];
int n;


bool check(ll x)
{
	 ll lage = 1;

	 for(int i=0 ; i<n ; i++)
	 {
	 	 if(lage<=a[i])
	 	 	x-=(a[i] - lage), lage++;
	 }

	 return x>=0;
}

void Solve()
{
        
       
       cin>>n;


     
       for(int i=0;  i<n ; i++)
       {
       	  cin>>a[i];
       }

       sort(a, a+n);

       ll low = 0, high = 1e18, mid;

       ll ans = high;

       while(low<=high)
       {
       	   mid = (low+high)>>1;

       	   if(check(mid))
       	   {
       	   	  ans = mid, high = mid - 1;
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