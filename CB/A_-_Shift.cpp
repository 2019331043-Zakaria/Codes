/*
* @Author: Zakaria 
* @Date:   2022-11-19 18:23:00
* @Last Modified time: 2022-11-19 18:24:42
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

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       if(k>=n)
       {
       	  for(int i=1 ; i<=n ; i++)
       	  	cout<<0<<" ";
       }
       else
       {
       	   for(int i=k+1;  i<=n ; i++)
       	   	cout<<a[i]<<" ";

       	   for(int i=1 ; i<=k ; i++)
       	   	cout<<0<<" ";
       }

       cout<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 