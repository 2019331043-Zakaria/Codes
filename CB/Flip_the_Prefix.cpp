/*
* @Author: Zakaria 
* @Date:   2022-12-28 20:35:05
* @Last Modified time: 2022-12-28 20:46:18
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
        
       int n, k;
       cin>>n>>k;

       string s;
       cin>>s;

       s = '*' + s;
       int cnt = 0;

       for(int i=1 ; i<=k ; i++)
       {
            if(s[i]!=s[i-1])
            	cnt++;
       }

       int ans = n;

       if(s[k]=='1')
       	ans = min(ans, cnt - 1);
       else
       	ans = min(ans, cnt);

       for(int i=k+1 ; i<=n ; i++)
       {
       	  if(s[i-k+1]!=s[i-k])
       	  	cnt--;
       	  if(s[i]!=s[i-1])
       	  	cnt++;

       	  if(s[i]=='1')
       	  	ans = min(ans, cnt - 1);
       	  else
       	  	ans = min(ans, cnt);
       }

       cout<<ans<<endl;
      
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