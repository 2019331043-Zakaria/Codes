/*
* @Author: Zakaria 
* @Date:   2023-03-02 21:04:04
* @Last Modified time: 2023-03-02 22:39:10
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

      
     int ans = 0;
    // cout<<dist<<endl;
     for(int i=2 ; i<s.size() ; i++)
     {
     	 if(s[i]==s[i-2])
     	 	ans++;
     	
     }

  
     cout<<n - 1 - ans<<endl;

     
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