/*
* @Author: Zakaria 
* @Date:   2022-12-03 22:56:52
* @Last Modified time: 2022-12-03 23:11:16
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

ll Check(ll x, ll y, ll lagbe)
{
       ll temp = y;
       ll res = 0;

       while(temp<=x)
       	res+=x/temp, temp*=y;

       return res>=lagbe;
}

void Solve()
{
        
        ll n;
        cin>>n;

        map<ll, ll>m;
        ll temp = n;

        for(ll i = 2 ; i*i<=n ; i++)
        {
        	while(temp%i==0)
        		m[i]++, temp/=i;
        }

        if(temp>1)
        	m[temp]++;
        
        ll ans = 1;


        for(auto i:m)
        {
             
             ll temp = i.f;
             ll lagbe = i.s;
             ll low = ans, high = n;
             ll pans = n;

             while(low<=high)
             {
                 
                 ll mid = (low+high)/2;
                 if(Check(mid, temp, lagbe))
                 	high = mid - 1, pans = mid;
                 else
                 	low = mid + 1;
                 
             }

             ans = max(ans, pans);
        }

        cout<<ans<<endl;



}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 