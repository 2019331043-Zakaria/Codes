/*
* @Author: Zakaria 
* @Date:   2023-01-03 21:35:07
* @Last Modified time: 2023-01-04 00:59:06
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
        
       int n, m;
       cin>>n>>m;

       ll a[n+1];

       for(int i=1 ; i<=n ; i++)
       	cin>>a[i];


       ll ans = 0;
       


       if(m>1)
       {
             
            
             ll pans = 0;
             if(a[m]<=0)
             	pans = a[m];
             else
             	pans = -1*a[m], ans++;

             priority_queue<ll>q;

             for(int i=m-1 ; i>=1 ; i--)
             {
                 if(a[i]>0)
                 	q.push(a[i]);

                 pans+=a[i];

                 while(pans>0 && q.size())
                 {
                 	 pans-=(2LL*q.top());
                 	 ans++;
                 	 q.pop();
                 }
             }
       }
       
    //   cout<<ans<<endl;

       ll pans = 0;

       priority_queue<ll>q;

       for(int i=m+1 ; i<=n ; i++)
       {
       	 if(a[i]<0)
       	 {
       	 	q.push(-1*a[i]);
       	 }
       	 pans+=a[i];

       	 while(pans<0 && q.size())
       	 {
       	 	pans+=(2LL*q.top());
       	 	ans++;
       	 	q.pop();
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