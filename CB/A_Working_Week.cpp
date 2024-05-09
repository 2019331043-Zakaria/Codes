/*
* @Author: Zakaria 
* @Date:   2022-10-02 20:35:16
* @Last Modified time: 2022-10-02 21:20:35
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

ll n;
bool check(ll mid)
{
	    ll x=1+mid+1+mid+mid+1;
	    if(x+3<=n)
	    	return 1;
	    else
	    	return 0;

}
void Solve()
{
        
        
        cin>>n;


        ll low=0, high=n-1;
        ll ans=0;

        while(low<=high)
        {
        	 ll mid=(low+high)/2;
             if(check(mid))
             	ans=mid, low=mid+1;
             else
             	high=mid-1;
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