/*
* @Author: Zakaria 
* @Date:   2022-09-30 20:37:00
* @Last Modified time: 2022-09-30 20:54:55
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

       ll a[n], b[n];

       for(int i=0 ; i<n ; i++)
       	cin>>a[i];

       vector<ll>fire, forst;
       
       ll mnfire=LLONG_MAX, mnforst=LLONG_MAX;

       for(int i=0 ; i<n ; i++)
       {
       	   cin>>b[i];
       	   if(a[i]==0)
       	   	forst.push_back(b[i]), mnforst=min(mnforst, b[i]);
       	   else
       	   	fire.push_back(b[i]), mnfire=min(mnfire, b[i]);
       }

       sort(forst.begin(), forst.end());
        sort(fire.begin(), fire.end());

       vector<ll>tempfire=fire;
       vector<ll>tempforst=forst;

       ll ans=0;

       if(tempfire.size())
       {
            ll ans1=tempfire[0];
            bool ok=1;

            while(1)
            {
            	 if(ok && tempforst.size())
            	 {
                      ans1+=2LL*tempforst.back();
                      tempforst.pop_back();
            	 }
            	 else
            	 	break;

            	 if(tempfire.size()>1)
            	 {
            	 	 ans1+=2LL*tempfire.back();
            	 	 tempfire.pop_back();
            	 }
            	 else
            	 	ok=0;
            }

            while(tempfire.size()>1)
            	ans1+=tempfire.back(), tempfire.pop_back();
            while(tempforst.size())
            	ans1+=tempforst.back(), tempforst.pop_back();

            ans=max(ans1, ans);

       }
       
       tempfire=forst;
       tempforst=fire;

       if(tempfire.size())
       {
            ll ans1=tempfire[0];
            bool ok=1;

            while(1)
            {
            	 if(ok && tempforst.size())
            	 {
                      ans1+=2LL*tempforst.back();
                      tempforst.pop_back();
            	 }
            	 else
            	 	break;

            	 if(tempfire.size()>1)
            	 {
            	 	 ans1+=2LL*tempfire.back();
            	 	 tempfire.pop_back();
            	 }
            	 else
            	 	ok=0;
            }

            while(tempfire.size()>1)
            	ans1+=tempfire.back(), tempfire.pop_back();
            while(tempforst.size())
            	ans1+=tempforst.back(), tempforst.pop_back();

            ans=max(ans1, ans);

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