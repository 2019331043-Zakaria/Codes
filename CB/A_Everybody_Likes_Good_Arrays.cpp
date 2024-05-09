/*
* @Author: Zakaria 
* @Date:   2023-01-21 20:35:19
* @Last Modified time: 2023-01-21 20:38:53
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
       ll a[n+1];
       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];

       map<int, int>m;

       m[a[1]%2]++;

       int ans = 0;

       for(int i=2 ; i<=n ; i++)
       {
       	   if(a[i-1]%2 != a[i]%2)
       	   {
       	   	  ans+=(m[a[i-1]%2]-1);
       	   	  m[a[i-1]%2]=0;
       	   	  m[a[i]%2]++;
       	   }
       	   else
       	   	m[a[i]%2]++;
       }

       if(m[0])
       	ans+=m[0]-1;
       else if(m[1])
       	ans+=m[1] - 1;

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