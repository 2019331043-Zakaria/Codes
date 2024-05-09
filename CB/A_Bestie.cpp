/*
* @Author: Zakaria 
* @Date:   2022-10-23 16:08:28
* @Last Modified time: 2022-10-24 21:07:29
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

       int G=0;
       int a[n+1];

       for(int i=1 ; i<=n ; i++)
       {
       	   cin>>a[i];
       	   G=GCD(G, a[i]);
       }

       if(G==1)
       {
       	   cout<<0<<endl;
       	   return ;
       }

       int ans = 3;


       for(int i=1 ; i<=n ; i++)
       {
       	  if(GCD(G, i)==1)
       	  {
       	  	 ans=min(ans, n-i+1);
       	  }
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