/*
* @Author: Zakaria 
* @Date:   2023-01-27 21:50:48
* @Last Modified time: 2023-01-27 22:06:19
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

       ll sum = n+n;
       
       ll temp = n ;
       
       sum = n/2;




       ll a = 0, b = 0;

       for(int i=0 ; i<32 ; i++)
       {
       	   int pans = sum&(1LL<<i);
       	   int lans = temp&(1LL<<i);

       	   if(pans==0 && lans==0)
       	   	continue;
       	   else if(!pans && lans)
       	   {
       	   	  a = (1LL<<i)|a;
       	   }
       	   else if(pans && !lans)
       	   {
       	   	  a = (1LL<<i)|a;
       	   	  b = (1LL<<i)|b;
       	   }
       	   else
       	   {
       	   	   cout<<-1<<endl;
       	   	   return ;
       	   }
       }
       if(a==0 || b==0)
       {
       	 cout<<-1<<endl;
       	 return ;
       }

       if((a+b)!=2LL*(a^b))
       {
       	  cout<<-1<<endl;
       	  return ;
       }
       cout<<a<<" "<<b<<endl;
      
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