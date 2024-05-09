/*
* @Author: Zakaria 
* @Date:   2022-12-05 01:20:28
* @Last Modified time: 2022-12-05 03:05:06
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
        
       ll a00, a01, a10, a11;
       cin>>a00>>a01>>a10>>a11;

       

       ll zero = 0, one = 0;

       bool ok1 = 0, ok0 = 0;

       for(ll i = 0 ; i<N ; i++)
       {
       	   if((i*(i-1))/2==a00)
       	   	zero = i, ok0=1;

       	   if((i*(i-1))/2==a11)
       	   	one = i, ok1=1;
       }


       if(!ok0 || !ok1)
       {
       	 cout<<"Impossible"<<endl;
       	 return ;
       }
       

      

       if(a00==0 && a11==0)
       {
       	  if(a10==1 && a01==0)
       	  	cout<<10<<endl;
       	  else if(a10==0 && a01==1)
       	  	cout<<"01"<<endl;
       	  else if(a10==0 && a01==0)
       	  	cout<<0<<endl;
       	  else
       	  	cout<<"Impossible"<<endl;

       	  return ;
       }

       if(a00==0 && a11)
       {
       	   if(a01==0 && a10==0)
       	   {
       	   	  for(int i=1 ; i<=one ; i++)
       	   	  	cout<<1;
       	   	  return ;
       	   }

       }

       if(a00 && a11==0)
       {
       	   if(a01==0 && a10==0)
       	   {
       	   	  for(int i=1 ; i<=zero ; i++)
       	   	  	cout<<0;
       	   	  return ;
       	   }

       }
    

       if(one*zero!=a01+a10)
       {
       	  cout<<"Impossible"<<endl;
       	  return ;
       }

       ll pans = a01/one;

       for(int i=1 ;i<=pans ; i++)
       	cout<<0, zero--;

       pans = a01%one;

       
   	  for(int i=1 ; i<=one - pans ; i++)
   	  	cout<<1;

   	  if(pans)
   	  	cout<<0, zero--;
   	  for(int i=1 ; i<=pans ; i++)
   	  	cout<<1;

   	  while(zero--)
   	  	cout<<0;

   	  cout<<endl;



       	  


      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 