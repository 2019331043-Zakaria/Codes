/*
* @Author: Zakaria 
* @Date:   2022-09-04 15:51:09
* @Last Modified time: 2022-09-04 17:38:44
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

bool is_prime(ll x)
{
         if(x==1)
         return 0;
     if(x==2)
        return 1;
     if(x%2==0)
        return 0;

         for(ll i=2 ; i*i<=x ; i++)
         {
                 if(x%i==0)
                        return 0;
         }

         return 1;
}
void Solve()
{
        
        ll n;
        cin>>n;

        if(n==3)
        {
                 cout<<1<<endl;
                 cout<<3<<endl;
                 return ;
        }
        if(n==4)
        {
                 cout<<2<<endl;
                 cout<<2<<" "<<2<<endl;
                 return ;
        }
        if(n==5)
        {
                 cout<<2<<endl;
                 cout<<3<<" "<<2<<endl;
                 return ;
        }
        if(n==6)
        {
                 cout<<2<<endl;
                 cout<<3<<" "<<3<<endl;
                 return ;
        }
        if(n==7)
        {
                 cout<<2<<endl;
                 cout<<5<<" "<<2<<endl;
                 return ;
        }

        if(n%2)
        {

                  n-=3;
                      
                   for(ll i=2 ; i<=n ; i++)
                           {
                                
                                 if(is_prime(i) && is_prime(n-i))
                                 {
                                         cout<<3<<endl;
                                         cout<<3<<" "<<i<<" "<<n-i<<endl;
                                         return ;
                                 }

                           } 
               

        }
        else
        {
                      for(ll i=2 ; i<=n ; i++)
                           {
                                
                                 if(is_prime(i) && is_prime(n-i))
                                 {
                                         cout<<2<<endl;
                                         cout<<i<<" "<<n-i<<endl;
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
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 