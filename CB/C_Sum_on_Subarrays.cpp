/*
* @Author: Zakaria 
* @Date:   2023-03-23 21:34:45
* @Last Modified time: 2023-03-24 14:10:20
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
        
      ll n, k;
      cin>>n>>k;

      if(k==0)
      {
          for(int i=1 ; i<=n ; i++)
            cout<<-1<<" ";
          cout<<endl;
          return ;
      }
      int lagbe = 0;

      for(ll i=0 ; i<=n ; i++)
      {
      	   ll temp = (i*(i+1))/2;

      	   if(temp<=k)
      	   {
      	   	   lagbe = i;
      	   }
      }

    
      ll baki = k - (lagbe*(lagbe+1))/2;
      vector<int>v;

      for(int i=1 ; i<=lagbe ; i++)
        v.push_back(2);

      if(baki==0)
      {
         while(v.size()!=n)
            v.push_back(-1000);

         for(auto i:v)
            cout<<i<<" ";
         cout<<endl;
         return ;
      }

      

      

      int temp = 1 + (v.size() - baki)*2;

      v.push_back(-temp);

      while(v.size()!=n)
            v.push_back(-1000);

         for(auto i:v)
            cout<<i<<" ";
         cout<<endl;



      
      
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