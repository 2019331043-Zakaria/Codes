/*
* @Author: Zakaria 
* @Date:   2023-02-28 21:05:36
* @Last Modified time: 2023-03-04 13:09:34
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
const int N = 2e6+6;

void Solve()
{
      
      
      int l , r;
     
      cin>>l>>r;
      ll len = 0;

      ll temp = l;
      ll mult = 1;
      ll last = l;
      while(1)
      {
      	  if(temp*mult<=r)
      	  	len++, last = temp*mult;
      	  else
      	  	break;

      	  mult*=2;
      }

      if(len==1)
      {
      	 cout<<1<<" "<<r-l+1<<endl;
      	 return ;
      } 
     
     // cout<<last<<endl;
      last/=l;

      int ans = r/last - l + 1;
      last/=2;
      last*=3;
   //   cout<<last<<endl;

      ans+=max(0LL, ((r/last) - l + 1)*(len - 1));

      cout<<len<<" "<<ans<<endl;


    
      
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