/*
* @Author: Zakaria 
* @Date:   2022-09-05 09:43:01
* @Last Modified time: 2022-09-05 09:48:39
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
ll a[N];

void Solve()
{

        int n;
        cin>>n;

        for(int i=1 ; i<=n ; i++) cin>>a[i];

        for(int i=30 ; i>=0 ; i--)
        {
              ll val=1LL<<i;
              vector<ll>res;
              ll tot=1LL<<30;
              tot--;

              for(int j=1 ; j<=n ; j++)
              {
                  if(a[j]&val)
                  {
                      tot&=a[j];
                      res.push_back(a[j]);
                  }
              } 

              if(tot%val==0)
              {
                 cout<<res.size()<<endl;
                 for(auto i:res)
                 cout<<i<<" ";
                 cout<<endl;
                 return ;
              }
        }

        cout<<-1<<endl;   
            
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 