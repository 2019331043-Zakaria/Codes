/*
* @Author: Zakaria 
* @Date:   2022-10-10 20:43:27
* @Last Modified time: 2022-10-10 21:19:06
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

       ll a[n+1];

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       for(int i=3 ; i<=n ; i++)
       {
       	  ll G=GCD(a[i-2], a[i]);
       	  if(a[i-1]%G)
       	  {
       	  	cout<<"NO"<<endl;
       	  	return ;
       	  }
       }

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