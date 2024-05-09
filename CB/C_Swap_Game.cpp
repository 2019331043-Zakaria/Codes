/*
* @Author: Zakaria 
* @Date:   2022-11-04 21:45:23
* @Last Modified time: 2022-11-04 23:52:29
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
        
        ll n;
        cin>>n;

        ll sum = 0;
        ll a[n+1];

        ll one = 0;

        ll even = 0;
        
        ll mn = 1e9+7;

        for(int i=1 ; i<=n ; i++)
        {
        	cin>>a[i];
        	sum+=a[i];
        	if(a[i]%2==0)
        		even++;
        	one+=(a[i]==1);

        	mn = min(mn, a[i]);


        }
        
        if(mn==a[1])
                cout<<"Bob"<<endl;
        else
                cout<<"Alice"<<endl;
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