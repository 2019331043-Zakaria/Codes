/*
* @Author: Zakaria 
* @Date:   2022-10-15 20:37:02
* @Last Modified time: 2022-10-15 20:37:53
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

       int one=0;

       for(int i=1 ; i<=n ; i++)
       {
       	  int x;
       	  cin>>x;
       	  if(x)
       	  	one=1;
       }

       if(one)
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