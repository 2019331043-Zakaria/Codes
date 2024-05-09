/*
* @Author: Zakaria 
* @Date:   2022-09-29 20:44:51
* @Last Modified time: 2022-09-30 11:00:01
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

       int a[n+1];
       for(int i=1 ; i<=n ; i++)
       {
       	  cin>>a[i];
       }

       int ans[n+1];
       ans[1]=a[1];

       bool ok=0;

       for(int i=2 ; i<=n ; i++)
       {
       	   if(a[i]==0)
       	   {
       	   	  ans[i]=ans[i-1];
       	   	  continue;
       	   }

       	   if(ans[i-1]-a[i]>=0 && ans[i-1]+a[i]>=0)
       	   {
       	   	  cout<<-1<<endl;
       	   	  return ;

       	   }
       	   ans[i]=ans[i-1]+a[i];
       }

       for(int i=1 ; i<=n ; i++)
       	cout<<ans[i]<<" ";
       cout<<endl;
      
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