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
int n, k;
int dp[N];
int a[N];

int foo(int x)
{
     if(x<=0)
     return 0;

     if(~dp[x])
     return dp[x];

     int mx=0;

     for(int i=0 ; i<k ; i++)
     {
        if(x>=a[i])
        mx = max(mx, x - foo(x-a[i]));
     }

     return dp[x] = mx;
}

void Solve()
{
        

       cin>>n>>k;
     
       for(int i=0 ; i<k ; i++)
       {
           cin>>a[i];
          
       }
       
       for(int i=0 ; i<=n ; i++)
       dp[i]=-1;

       cout<<foo(n)<<endl;
      
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