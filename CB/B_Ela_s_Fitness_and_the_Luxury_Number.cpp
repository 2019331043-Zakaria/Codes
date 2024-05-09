/*
* @Author: Zakaria 
* @Date:   2022-10-07 21:15:23
* @Last Modified time: 2022-10-07 22:15:04
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

ll foo(ll a, ll b, ll m)
{
   
    if (a%m==0)
        return (b/m)-(a/m)+1;
 
    return (b/m)-(a/m);
}


ll findsqr(ll x)
{
        
        ll low=1, high=1e9;
        ll ans=1;

        while(low<=high)
        {
        	 ll mid=(low+high)/2;

        	 ll temp=mid*mid;
             
             if(temp==x)
             	return mid;

        	 if(temp<=x)
        	 	ans=mid, low=mid+1;
        	 else
        	 	high=mid-1;
        }

        return ans;
}
ll find(ll r)
{
	   
        if(r==0)
        	return 0;
        if(r==1)
        	return 1;
        if(r==2)
        	return 2;

	    ll p=findsqr(r);

       

        ll ans=3LL*(p);
        ans-=3;
        ans++;

        ll pans=p*p;
        
        
        ans+=foo(pans+1, r, p);

        return ans;

}


void Solve()
{
        
        ll l, r;
        cin>>l>>r;

       

        cout<<find(r) - find(l-1)<<endl;

        
      
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