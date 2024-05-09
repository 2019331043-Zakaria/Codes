/*
* @Author: Zakaria 
* @Date:   2023-01-03 11:05:15
* @Last Modified time: 2023-01-03 11:10:27
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

       for(int i=0 ; i<n ; i++)
       	cin>>b[i];

       for(int i=0 ; i<n ; i++)
       {
       	  ll temp = min(a[i], b[i]);

       	  ll TempMin = max(a[i], b[i]);

       	  a[i] = TempMin;
       	  b[i] = temp;
       }

       ll ans = 1;

       sort(a, a+n);
       sort(b, b+n);

       cout<<a[n-1]*b[n-1]<<endl;
      
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