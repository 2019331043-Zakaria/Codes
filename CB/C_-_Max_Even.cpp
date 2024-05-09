/*
* @Author: Zakaria 
* @Date:   2022-10-08 18:07:57
* @Last Modified time: 2022-10-08 18:13:30
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

       vector<ll>even, odd;

       for(int i=1 ; i<=n ; i++)
       {
       	    int x;
       	    cin>>x;
       	    if(x%2)
       	    	odd.push_back(x);
       	    else
       	    	even.push_back(x);
       }

       sort(odd.begin(), odd.end());
       sort(even.begin(), even.end());

       ll ans=-1;

       if(odd.size()>=2)
       {
       	  ans=max(ans, odd[odd.size()-1]+odd[odd.size()-2]);
       }

       if(even.size()>=2)
       {
       	  ll temp=0;
       	  temp=even.back();
       	  even.pop_back();
       	 
       	  if(even.size())
       	  	temp+=even.back();
       	  ans=max(ans, temp);
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