/*
* @Author: Zakaria 
* @Date:   2022-11-21 20:36:53
* @Last Modified time: 2022-11-21 20:39:30
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
       	cin>>a[i];

       int mx = 0;
       int cnt = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	   mx = max(mx, a[i]);
       }

       for(int i=1 ; i<=n ; i++)
       {
       	  if(a[i]==mx)
       	  	cnt++;
       }

       if(cnt==1)
       {
       	   int sec = 0;

       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  if(a[i]!=mx)
       	   	  	sec = max(sec, a[i]);
       	   }

       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  if(a[i]==mx)
       	   	  	cout<<a[i]-sec<<" ";
       	   	  else
       	   	  	cout<<a[i] - mx<<" ";
       	   }
       }
       else
       {
       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  
       	   	  	cout<<a[i] - mx<<" ";
       	   }
       }

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