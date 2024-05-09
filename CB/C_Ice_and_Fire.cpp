/*
* @Author: Zakaria 
* @Date:   2022-12-17 21:03:14
* @Last Modified time: 2022-12-17 21:58:40
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
       string s;
       cin>>s;
 
       int one = 0, zero = 0;
       int temp = 2;
       for(auto i:s)
       {
          
          if(i=='1')
          {
          	 cout<<temp-(one+1)<<" ";
          	 one++;
          	 zero =0;
          }
          else
          {
          	cout<<temp - (zero+1)<<" ";
          	zero++;
          	one=0;
          }
          temp++;
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