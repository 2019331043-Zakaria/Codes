/*
* @Author: Zakaria 
* @Date:   2022-09-30 20:55:38
* @Last Modified time: 2022-10-01 00:34:01
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
        
       ll n, k;
       cin>>n>>k;

       ll a[k];

       for(int i=0 ; i<k ; i++)
       {
       	   cin>>a[i];
       }

       

        vector<ll>v;
   	    
   	    if(k==1)
   	    {
   	    	 cout<<"YES"<<endl;
   	    	 return ;
   	    }

   	    for(int i=1 ; i<k ; i++)
   	    {
   	    	 v.push_back(a[i]-a[i-1]);
   	    }

   	

   	    if(!is_sorted(v.begin(), v.end()))
   	    {
   	    	cout<<"NO"<<endl;
   	    	return ;
   	    }
   	    
   	    if((n-k+1)*v[0]>=a[0])
   	    	cout<<"YES"<<endl;
   	    else
   	    	cout<<"NO"<<endl;


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