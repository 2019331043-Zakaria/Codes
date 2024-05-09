/*
* @Author: Zakaria 
* @Date:   2022-11-09 21:13:24
* @Last Modified time: 2022-11-09 21:25:30
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

       ll a[n+n];

       for(int i=0 ; i<n+n ; i++)
       {
       	   cin>>a[i];
       }

       sort(a, a+n+n);
       map<ll, int>m;

       for(int i=n ; i<n+n ; i++)
       {
           // cout<<a[i] - a[i-n]<<" ";
            m[a[i] - a[i-n]]++;
       }

       int mx = 0;

       for(auto i:m)
       {
       	 if(i.f==0)
       	 	mx = max(mx, i.s);
         else
         	mx = max(mx, (i.s+1)/2);
       }
       
      // cout<<mx<<endl;

       if(mx>(n+1)/2)
       {
       	  cout<<"NO"<<endl;
       }
       else
       	cout<<"YES"<<endl;
      
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