/*
* @Author: Zakaria 
* @Date:   2022-12-27 21:08:53
* @Last Modified time: 2022-12-27 22:30:50
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
const int N = 600000;

vector<int>pans;
int m[N];
int a[N];
void Solve()
{
        
       ll n;
       cin>>n;

       

       for(int i = 1 ; i<=n ; i++)
       {
       	  cin>>a[i];
       }
       
      
       ll Bad = 0;

   	  
   	  m[0] = 1;
      ll Current = 0;
   	  for(int j=1 ; j<=n ; j++)
   	  {
   	  	 Current^=a[j];

   	  	 for(auto k:pans)
   	  	 {
            int temp = Current^k;
            
            //cout<<temp<<" "<<m[temp]<<endl;
            if(m[temp]>0)
   	  	 	Bad+=m[temp];
   	  	 	
   	  	 }

   	  	 m[Current]++;
   	  }
       
       Current = 0;
       m[Current] = 0;
       for(int i=1 ; i<=n ; i++)
       {
       	  
       	  Current^=a[i];
       	  m[Current] = 0;
       }

     //  cout<<Bad<<endl;

       ll tot = (n*(n+1))/2;

       cout<<tot - Bad<<endl;
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
       
       ll temp = 1LL<<18;

       for(int i=0 ; i<=temp ; i++)
       	m[i] = 0;


       for(ll i= 0 ; i*i<=temp ; i++)
       {
      
       	 pans.push_back(i*i);
       }
        
        
      
        int tt=1;
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 