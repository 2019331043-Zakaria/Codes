/*
* @Author: Zakaria 
* @Date:   2022-10-15 20:45:26
* @Last Modified time: 2022-10-15 20:52:42
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

       int a[n];
       
       int sum=0;
       int totzero=0;

       for(int i=0 ; i<n ; i++)
       {
       	  cin>>a[i];
       	  sum+=a[i];
       	  if(a[i]==0)
       	  	totzero++;
       }
       


       int ans = n - sum;

      // cout<<ans<<endl;

       int one=0;
       int zero=0;

       for(int i=0 ; i<n ; i++)
       {
       	    if(a[i]==0)
       	    {
                 
                 zero++;
                 
                 int temp = one;

                 int bakizero=totzero-zero;

                 if(bakizero>one)
                 	temp+=(bakizero-one);


                 ans=min(ans, temp);


       	    }
       	    else
       	    	one++;
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