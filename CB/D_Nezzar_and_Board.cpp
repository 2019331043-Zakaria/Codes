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
        cin>>a[i];

        ll G=0;

        for(int i=1 ; i<n ; i++)
        G=GCD(G, abs(a[i]-a[0]));

        if(abs(k - a[0])%G)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
      
      
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