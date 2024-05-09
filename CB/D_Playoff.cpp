/*
* @Author: Zakaria 
* @Date:   2022-12-16 21:30:04
* @Last Modified time: 2022-12-16 22:29:36
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

       

       //cout<<q.size()<<endl;

       int one = 0, zero = 0;

       for(auto i:s)
       {
       	   if(i=='1')
       	   	one++;
       	   else
       	   	zero++;
       }

       if(one==n)
       {
       	   cout<<(1<<n)<<endl;
       	   return ;

       }
       if(zero==n)
       {
       	  cout<<1<<endl;
       	  return ;
       }

       
             int choto = 1, boro = (1<<n) ;

             for(auto k:s)
             {
             	 if(k=='1')
             	 {
             	 	 choto+=2;
             	 }
             	 else
             	 {
             	 	boro-=2;
             	 }
             }

             cout<<choto<<" "<<boro<<endl;

            
       
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 