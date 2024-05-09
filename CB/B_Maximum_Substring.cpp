/*
* @Author: Zakaria 
* @Date:   2022-11-06 20:39:28
* @Last Modified time: 2022-11-06 20:48:57
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

ll foo1(string s, char c)
{
       
       int n = s.size();

       s = '*' + s;

       int cum[n+1];

       cum[0] = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	   cum[i] = cum[i-1];

       	   if(s[i]==c)
       	   	cum[i]++;
       }

       int low = 1, high = n, mid;

       int ans = 0;

       while(low<=high)
       {
       	    mid = (low+high)/2;

       	    bool ok = 0;

       	    for(int i=mid ; i<=n ; i++)
       	    {
                 if(cum[i] - cum[i-mid]==mid)
                 {
                 	ok = 1;
                 	break;
                 }
       	    }

       	    if(ok)
       	    {
       	    	ans = mid;
       	    	low = mid+1;
       	    }
       	    else
       	    	high = mid - 1;
       }

       return ans;


}
void Solve()
{
        
       int n;
       cin>>n;

       string s;
       cin>>s;

       ll one = 0, zero = 0;

       for(auto i:s)
       {
       	  if(i=='1')
       	  	one++;
       	  else
       	  	zero++;
       }

       ll ans = one*zero;


       ll temp = foo1(s, '1');

       ans = max(ans, temp*temp);

       temp = foo1(s, '0');

       ans = max(ans, temp*temp);
       
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