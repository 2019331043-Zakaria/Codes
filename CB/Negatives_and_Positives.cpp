/*
* @Author: Zakaria 
* @Date:   2023-02-03 20:39:53
* @Last Modified time: 2023-02-03 21:40:31
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

       priority_queue<ll>pq;

       ll ans = 0;
       int neg = 0;
       int zero = 0;

       for(int i=1 ; i<=n ; i++)
       {
       	  ll x;
       	  cin>>x;
       	  pq.push(abs(x));

       	  if(x<0)
       	  	neg++;
       	 
       }

       ll last = 0;

       while(pq.size())
       {
       	  last = pq.top();
       	  ans+=last;
       	  pq.pop();
       }

       if(neg%2)
       {
       	 ans-=last;
       	 ans-=last;
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