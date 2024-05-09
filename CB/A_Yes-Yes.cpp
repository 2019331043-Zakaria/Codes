/*
* @Author: Zakaria 
* @Date:   2022-11-18 20:36:18
* @Last Modified time: 2022-11-18 20:39:59
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
        
       string s;
       cin>>s;

       int n = s.size();

       bool ok = 1;

       for(int i=0 ; i<n ; i++)
       {
       	   if(i%3==0)
       	   {
       	   	   if(s[i]!='Y')
       	   	   	ok=0;
       	   }
       	   if(i%3==1)
       	   {
       	   	   if(s[i]!='e')
       	   	   	ok=0;
       	   }
       	   if(i%3==2)
       	   {
       	   	   if(s[i]!='s')
       	   	   	ok=0;
       	   }
       }

       if(ok)
       {
       	  cout<<"YES"<<endl;
       	  return ;
       }

       ok = 1;

       for(int i=0 ; i<n ; i++)
       {
       	   if(i%3==0)
       	   {
       	   	   if(s[i]!='e')
       	   	   	ok=0;
       	   }
       	   if(i%3==1)
       	   {
       	   	   if(s[i]!='s')
       	   	   	ok=0;
       	   }
       	   if(i%3==2)
       	   {
       	   	   if(s[i]!='Y')
       	   	   	ok=0;
       	   }
       }

        if(ok)
       {
       	  cout<<"YES"<<endl;
       	  return ;
       }

       ok = 1;

       for(int i=0 ; i<n ; i++)
       {
       	   if(i%3==0)
       	   {
       	   	   if(s[i]!='s')
       	   	   	ok=0;
       	   }
       	   if(i%3==1)
       	   {
       	   	   if(s[i]!='Y')
       	   	   	ok=0;
       	   }
       	   if(i%3==2)
       	   {
       	   	   if(s[i]!='e')
       	   	   	ok=0;
       	   }
       }

        if(ok)
       {
       	  cout<<"YES"<<endl;
       	  return ;
       }

       cout<<"NO"<<endl;



      
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