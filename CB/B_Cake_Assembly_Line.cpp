/*
* @Author: Zakaria 
* @Date:   2023-02-05 18:39:31
* @Last Modified time: 2023-02-05 20:05:13
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
        
      ll n, h, w;
      cin>>n>>h>>w;

      ll a[n];

      for(int i=0 ; i<n ; i++)
      	cin>>a[i];

      ll b[n];

      for(int i=0 ; i<n ; i++)
      	cin>>b[i];

      
    
      ll diff = 0;

      vector<ll>pans;

      ll temp = b[0] - a[0];
      
      pans.push_back(0);

      for(int i=1 ; i<n ; i++)
      {
          ll cakeleft = a[i] + temp + diff - h;
          ll cakeright = a[i] + temp + diff + h ;

          ll left = b[i] - w;
          
          if(left<cakeleft)
          {
          	 diff-=cakeleft - left;
          	 pans.push_back(diff);
          } 	

          ll right = b[i] + w;

          if(right>cakeright)
          {
          	 diff+=(right - cakeright);
          	 pans.push_back(diff);
          }

      //    cout<<left<<" coc "<<right<<endl;

      //    cout<<cakeleft<<" cake "<<cakeright<<endl;

      //    cout<<diff<<endl;
      }

  //    cout<<diff<<endl;

      for(int i=0 ; i<n ; i++)
      {
      	   ll cakeleft = a[i] + temp + diff - h;
           ll cakeright = a[i] + temp + diff + h ;

           ll left = b[i] - w;

           ll right = b[i] + w;

           if(left>=cakeleft && right<=cakeright)
           	continue;
           else
           {
           	  cout<<"NO"<<endl;
           	  return ;
           }

      }

      cout<<"YES"<<endl;


      
      
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