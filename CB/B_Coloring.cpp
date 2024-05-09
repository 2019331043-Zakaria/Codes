/*
* @Author: Zakaria 
* @Date:   2022-12-17 20:48:42
* @Last Modified time: 2022-12-18 03:01:07
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
        
      ll n, m, k;
      cin>>n>>m>>k;

      ll a[m];
      
      ll mx = 0;

      for(int i=0 ; i<m ; i++)
      	cin>>a[i];

     
     sort(a, a+m);
     reverse(a, a+m);
     

     for(int i=0 ; i<m ; i++)
     {
          ll temp = (a[i] - 1)*k;
          temp+=i+1;
          if(temp>n)
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