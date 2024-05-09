/*
* @Author: Zakaria 
* @Date:   2022-12-29 23:02:31
* @Last Modified time: 2022-12-29 23:06:28
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

       for(int i=0 ; i<n ; i++)
       {
       	  cin>>a[i];

       	  if(a[i]>1)
       	  	a[i] = 2;
       }

       if(is_sorted(a, a+n))
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