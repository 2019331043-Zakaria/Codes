/*
* @Author: Zakaria 
* @Date:   2023-03-17 18:16:17
* @Last Modified time: 2023-03-17 19:06:45
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
        
       double theta;
       cin>>theta;

       for(int i=0 ; i<12 ; i++)
       {
       	   for(int k=0 ; k<=59 ; k++)
       	   {
       	   	  double pans = 60*i - 11*k;
       	   	  pans = abs(pans)/2.;

       	   	  
       	   	  if(pans==theta)
       	   	  {
       	   	  	  if(i<10)
       	   	  	  {
       	   	  	  	 if(i==0)
       	   	  	  	 {
       	   	  	  	 	 cout<<12<<":";
       	   	  	  	 }
       	   	  	  	 else
       	   	  	  	 cout<<"0"<<i<<":";
       	   	  	  }
       	   	  	  else
       	   	  	  	cout<<i<<":";

       	   	  	  if(k<10)
       	   	  	  {
       	   	  	  	cout<<0<<k<<endl;
       	   	  	  }
       	   	  	  else
       	   	  	  	cout<<k<<endl;
       	   	  	  
       	   	  	  return ;
       	   	  }
       	   	  else if(360 - pans==theta)
       	   	  {
       	   	  	 if(i<10)
       	   	  	  {
       	   	  	  	 if(i==0)
       	   	  	  	 {
       	   	  	  	 	 cout<<12<<":";
       	   	  	  	 }
       	   	  	  	 else
       	   	  	  	 cout<<"0"<<i<<":";
       	   	  	  }
       	   	  	  else
       	   	  	  	cout<<i<<":";

       	   	  	  if(k<10)
       	   	  	  {
       	   	  	  	cout<<0<<k<<endl;
       	   	  	  }
       	   	  	  else
       	   	  	  	cout<<k<<endl;
       	   	  	  
       	   	  	  return ;
       	   	  }
       	   }
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