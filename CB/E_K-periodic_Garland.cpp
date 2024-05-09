/*
* @Author: Zakaria 
* @Date:   2022-10-25 16:49:38
* @Last Modified time: 2022-10-26 16:53:08
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

       int cum[n+1];
       cum[0] = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	   cum[i] = cum[i-1] + (s[i]=='1');
       }


       int tot = 0;
       for(auto i:s)
       	if(i=='1') tot++;

       int ans = tot;


       for(int i=1 ; i<=k ; i++)
       {
             int mx = 0;

             for(int j = i ; j<=n ; j+=k)  //maximum subarray sum
             {
                  if(s[j]=='1')
                    mx++;
                  else
                    mx--;
                  
                  mx = max(mx , 0);
                  ans = min(ans, tot - mx);
             }
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