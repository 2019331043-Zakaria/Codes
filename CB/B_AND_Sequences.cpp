/*
* @Author: Zakaria 
* @Date:   2022-10-28 11:56:44
* @Last Modified time: 2022-10-28 12:06:13
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

ll fact[N];


void Solve()
{
        
       int n;
       cin>>n;

       ll zero = 0;
       int mx = 0, mn = INT_MAX;

       int a[n];

       ll arrayand = -1;

       for(int i=0 ; i<n ; i++)
       {
            int x;
            cin>>x;
            
            a[i] = x;

            arrayand&=x;
          
            mn = min(mn, x);
            mx = max(mx, x);
       }



       if(mn==mx)
       {
       	   cout<<fact[n]<<endl;
       	   return ;
       }
       else
       {
       	   for(auto i:a)
       	   	if(i==arrayand)
       	   		zero++;
       	   	
           if(zero==0)
           	cout<<0<<endl;
           else
           {
           	   zero = (zero*(zero-1));
           	   cout<<(zero*fact[n-2])%mod<<endl;
           }
       }
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);


        fact[0] = 1;

        for(int i=1 ; i<N ; i++)
        	fact[i] = (fact[i-1]*i)%mod;
        
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 