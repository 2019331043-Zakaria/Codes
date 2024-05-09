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

int dp[55][55];
int a[55];
int n, len;

int foo(int l, int r)
{
    if(l+1==r)
        return 0;
    int &R = dp[l][r];
    if(R!=-1)
        return R;
    R = INT_MAX;
    for(int i=l+1; i<r ; i++)
     R = min(R, a[r] - a[l] + foo(l, i) + foo(i, r));

   return R;
}

void Solve()
{
        int t = 1;
        while(1)
        {
            
            cin>>len;
            if(len==0)
                return ;

            cin>>n;
            for(int i=1 ; i<=n ; i++)
                cin>>a[i];
         
            memset(dp, -1, sizeof(dp));
            a[n+1] = len;

            cout<<"The minimum cutting is "<<foo(0, n+1)<<"."<<endl;
        }
      
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