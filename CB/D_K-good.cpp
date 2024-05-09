/*
* @Author: Zakaria 
* @Date:   2022-12-28 21:25:04
* @Last Modified time: 2022-12-28 23:24:18
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
        
      ll n;
      cin>>n;

      if(n%2)
      {
      	  cout<<2<<endl;
      	  return ;
      }

      ll temp = n;

      while(temp%2==0)
      	temp/=2;

      if(temp==1)
      {
      	 cout<<-1<<endl;
      	 return ;
      }

      if(temp<=1e9 && temp*(temp+1)<=n+n)
      {
      	cout<<temp<<endl;
      	return ;
      }
      
      
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