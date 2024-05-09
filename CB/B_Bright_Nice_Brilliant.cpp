/*
* @Author: Zakaria 
* @Date:   2022-09-23 18:08:23
* @Last Modified time: 2022-09-23 18:26:31
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

       if(n<=2)
       {
       	   for(int i=1 ; i<=n ; i++)
       	   {
       	   	  for(int j=1 ; j<=i ; j++)
       	   	  	cout<<1<<" ";
       	   	  cout<<endl;
       	   }
       	   return ;
       }

         for(int i=1 ; i<=2 ; i++)
       	   {
       	   	  for(int j=1 ; j<=i ; j++)
       	   	  	cout<<1<<" ";
       	   	  cout<<endl;
       	   }


       	 for(int i=3 ; i<=n ; i++)
       	 {
       	 	  for(int j=1 ; j<=i ; j++)
       	 	  {
       	 	  	  if(j==1 || j==i)
       	 	  	  	cout<<1<<" ";
       	 	  	  else
       	 	  	  	cout<<0<<" ";
       	 	  }
       	 	  cout<<endl;
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