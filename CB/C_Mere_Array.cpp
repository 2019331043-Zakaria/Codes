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

        ll a[n];

        ll mn=LLONG_MAX;

        for(int i=0 ; i<n ; i++)
        {
             cin>>a[i];
             mn=min(mn, a[i]);
        }

        vector< ll > v;

        for(int i=0 ; i<n ; i++)
        {
            if(a[i]%mn==0)
            {
                 v.push_back(a[i]);
                 a[i]=-1;
            }
        }

        sort(v.rbegin(), v.rend());

        for(int i=0 ; i<n ; i++)
        {
             if(a[i]==-1)
             a[i]=v.back(), v.pop_back();
        }

        if(is_sorted(a, a+n))
         cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl;
      
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
