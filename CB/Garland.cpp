/*
* @Author: Zakaria 
* @Date:   2023-03-23 20:35:14
* @Last Modified time: 2023-03-23 20:41:28
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

      string s;
      cin>>s;

      sort(s.begin(),s.end());

      map<char, int>m;

      for(auto i:s)
      	m[i]++;

      
      int mx = 0;
      for(auto i:m)
      {
      	 mx = max(mx, i.s);
      }

      if(mx==4)
      {
      	 cout<<-1<<endl;
      	 return ;
      }
      if(mx==3)
      {
      	 cout<<6<<endl;
      	 return ;
      }
      cout<<4<<endl;
      
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