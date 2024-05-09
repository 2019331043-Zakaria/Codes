/*
* @Author: Zakaria 
* @Date:   2022-10-11 14:22:55
* @Last Modified time: 2022-10-11 14:28:59
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

        ll a[n+1];

        vector<ll>v;
        ll ans=0;
        int neg=0, pos=0;
        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	v.push_back(abs(a[i]));
        	ans+=abs(a[i]);
        	if(a[i]<=0)
        		neg=1;
        	if(a[i]>=0)
        		pos=1;
        }

        if(n==1)
        {
        	cout<<a[1]<<endl;
        	return ;
        }

        if(neg && pos)
        {
        	cout<<ans<<endl;
        	return ;
        }

        sort(v.rbegin(), v.rend());

        if(v.size()>1)
        {
        	ans-=2*v.back();
        }

        cout<<ans<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
        //cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 