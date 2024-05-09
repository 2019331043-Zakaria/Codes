/*
* @Author: Zakaria 
* @Date:   2022-11-18 20:45:40
* @Last Modified time: 2022-11-18 21:20:16
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
        
       ll l, r, x;
       cin>>l>>r>>x;
       ll a, b;
       cin>>a>>b;
       
       if(a<=b)
       {

	   	   ll dis = b - a;

	   	   ll ans = LLONG_MAX;



	   	   if(dis==0)
	   	   {
	   	   	  cout<<0<<endl;
	   	   	  return ;
	   	   }

	   	   if(dis>=x)
	   	   {
	   	   	  cout<<1<<endl;
	   	   	  return ;
	   	   }

	   	   ll jabo ;


	   	   if(r - a>=x)
	   	   {
	   	   	    if(r - b>=x)
	   	   	    {
	   	   	    	ans = min(ans, 2LL);
	   	   	    }
	   	   	    
	   	   	    if(b - l>=x)
	   	   	    {
	   	   	    	ans = min(ans, 3LL);
	   	   	    }
	   	   }

	   	   if(a - l>=x)
	   	   {
	   	   	    if(b - l>=x)
	   	   	    	ans = min(ans, 2LL);

	   	   	    if(r - b>=x)
	   	   	    	ans = min(ans, 3LL);
	   	   }

	   	   if(ans==LLONG_MAX)
	   	   	cout<<-1<<endl;
	   	   else
	   	   	cout<<ans<<endl;

   	   }
   	   else
   	   {
             ll dis = a - b;

            ll ans = LLONG_MAX;



	   	   if(dis==0)
	   	   {
	   	   	  cout<<0<<endl;
	   	   	  return ;
	   	   }

	   	   if(dis>=x)
	   	   {
	   	   	  cout<<1<<endl;
	   	   	  return ;
	   	   }

	   	   if(a - l>=x)
	   	   {
	   	   	   if(b-l>=x)
	   	   	   	ans = min(ans, 2LL);

	   	   	   if(r - b>=x)
	   	   	   	ans = min(ans, 3LL);
	   	   }

	   	   if(r - a>=x)
	   	   {
	   	   	   if(r - b>=x)
	   	   	   	ans = min(ans, 2LL);

	   	   	   if(b - l>=x)
	   	   	   	ans = min(ans, 3LL);
	   	   }

	   	   if(ans==LLONG_MAX)
	   	   	cout<<-1<<endl;
	   	   else
	   	   	cout<<ans<<endl;


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