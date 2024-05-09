/*
* @Author: Zakaria 
* @Date:   2022-09-23 19:29:55
* @Last Modified time: 2022-09-23 19:44:24
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
        
       int n, k;
       cin>>n>>k;

       ll a[n+1];
       ll cum[n+1];
       cum[0]=0;
       for(int i=1 ; i<=n ; i++)
       {
       	  cin>>a[i];
       	  cum[i]=cum[i-1]+a[i];
       }

       ll temp=0;

       bool ok=1;
       
       for(int i=k ; i>=1 ; i--)
       {
       	  temp+=a[i];
       	  if(temp<0)
       	  	ok=0;
       }

       if(ok)
       {
	       for(int i=k+1 ; i<=n ; i++)
	       {
	            temp+=a[i];
	            if(temp>=0)
	            {
	            	cout<<"YES"<<endl;
	            	return ;
	            }
	       }
	   }

       for(int i=0 ; i<=n ; i++)
       	cum[i]=0;
       
       ll sum=0;
       for(int i=k+1 ; i<=n ; i++)
       {
       	   sum+=a[i];
       }

       for(int i=k ; i>=1 ; i--)
       {
       	    sum+=a[i];
       	    if(sum>=0)
       	    {
       	    	cout<<"YES"<<endl;
       	    	return ;
       	    }
       }

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