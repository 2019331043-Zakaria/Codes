/*
* @Author: Zakaria 
* @Date:   2022-12-12 21:47:27
* @Last Modified time: 2022-12-13 00:44:30
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

#define sz 10000010
bool siv[sz];
int lps[sz]; 

void seive()
{
    long long  limit = sqrt(sz+1);
    
    for(int i=1 ; i<sz ; i++)
        lps[i] = i;

    for(int i=2 ; i<sz ; i+=2)
        lps[i] = 2;

    for (int  i=3; i<=limit; i+=2)
        if(!siv[i])
            for (int  j = i*i; j<sz; j+=i+i)
                siv[j] = 1, lps[j] = min(lps[j], i);
}

void Solve()
{
        
       ll a, b;
       cin>>a>>b;

       if(GCD(a, b)>1)
       {
       	  cout<<0<<endl;
       	  return ;
       }

       if(a+1==b)
       {
       	  cout<<-1<<endl;
       	  return ;
       }

       if(a%2==b%2)
       {
       	  cout<<1<<endl;
       	  return ;
       }


       ll pans = b - a;

       ll ans = 1e18;

       while(pans>1)
       {
           ll fact = lps[pans];

           ll temp = (a + fact - 1)/fact;

           temp*=fact;

           ans = min(ans, temp - a);

           pans/=fact;
       }

       cout<<ans<<endl;
       
       

       

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        seive();

        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 