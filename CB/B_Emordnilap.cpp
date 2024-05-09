/*
* @Author: Zakaria 
* @Date:   2023-01-21 20:39:54
* @Last Modified time: 2023-01-21 21:11:54
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

ll fact(ll n)
{
	ll ans =1 ;

	for(ll i=2 ; i<=n ; i++)
		ans*=i, ans%=mod;

	return ans;
}

void Solve()
{
        
      ll n;
      cin>>n;

      if(n==1)
      {
      	cout<<0<<endl;
      	return ;
      }

      ll ans = 2;

      ll temp = fact(n);

      

      ans*=temp;
      ans%=mod;

      //cout<<ans<<" => \n";
     // cout<<ans<<endl;

      ll result = ans;

      for(ll i=2 ; i<n ; i++)
      {
      	ll ehhe = ans*i;
      	ehhe%=mod;

     // 	cout<<ehhe<<endl;

      	result+=ehhe;
      	result%=mod;
      }

      cout<<result<<endl;

      
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