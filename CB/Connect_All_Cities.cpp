/*
* @Author: Zakaria 
* @Date:   2022-11-24 01:06:27
* @Last Modified time: 2022-11-24 13:34:59
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

        for(int i = 1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	v.push_back(a[i]);
        }

        ll ans = 0;

        for(int i=0 ; i<=30 ; i++)
        {
        	ll temp = 0;
        	vector<ll>pans;
        	ll cnt = 0;

        	for(auto j : v)
        	{
                if(j & (1LL<<i))
                {
                    cnt++;
                    temp|=j;
                }
                else
                {
                	pans.push_back(j);
                }
        	}

            if(cnt)
            	ans+=(cnt-1)*(1LL<<i);

            if(temp)
            pans.push_back(temp);
            v = pans;
        }



        if(v.size()>1)
        	cout<<-1<<endl;
        else
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