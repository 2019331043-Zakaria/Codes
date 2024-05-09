/*
* @Author: Zakaria 
* @Date:   2023-03-26 00:58:22
* @Last Modified time: 2023-03-26 01:00:10
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

       ll X = 0, S = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	   ll p;
       	   cin>>p;
       	   S+=p;
       	   X^=p;
       }
       cout<<2<<endl;
       cout<<X<<" "<<S+X<<endl;
      
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