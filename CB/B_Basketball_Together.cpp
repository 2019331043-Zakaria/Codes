/*
* @Author: Zakaria 
* @Date:   2022-09-04 18:18:14
* @Last Modified time: 2022-09-04 19:55:40
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
#define  MAX         200002
#define  eps         1e-6
typedef long long ll;
using namespace std;

const int N = 1e5+6;

void Solve()
{
        
       ll n, k;
       cin>>n>>k;

       ll a[n];

       for(int i=0 ; i<n ; i++)
       {
         cin>>a[i];
       }

       sort(a, a+n);


       deque<ll>q;
       for(auto i:a)
       q.push_front(i);

       ll ans=0;

       while(q.size())
       {
            ll temp=q.front();

            q.pop_front();

            ll sum=temp;

            while(sum<=k)
            {
                  if(q.size())
                  {
                      sum+=temp;
                      q.pop_back();
                  }
                  else
                   break;
            }
           
            if(sum>k)
            ans++;
       }
       cout<<ans<<endl;
       
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
       // cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 