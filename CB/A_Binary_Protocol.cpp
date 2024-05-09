/*
* @Author: Zakaria 
* @Date:   2023-01-01 19:55:13
* @Last Modified time: 2023-01-01 20:10:46
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

      int cnt=0;

      string ans;

      for(auto i:s)
      {
      	 if(i=='1')
      	 {
      	 	cnt++;
      	 }
      	 else
      	 {
      	 	ans.push_back('0' + cnt);
      	 	cnt = 0;
      	 }
      }
      ans.push_back('0' + cnt);

      cout<<ans<<endl;




      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 