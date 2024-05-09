/*
* @Author: Zakaria 
* @Date:   2022-10-05 21:16:10
* @Last Modified time: 2022-10-05 21:21:27
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

        ll pre=0;
        ll temp=0;
        for(int i=1 ; i<=n ; i++)
        {
             temp+=a[i];
             pre=max(pre, temp);
        }
        temp=0;
        for(int i=n ; i>=1 ; i--)
        {
           temp+=a[i];
           pre=max(pre, temp);
        }

        int m;
        cin>>m;

        for(int i=1 ;i<=m ; i++)
        {
        	 int x;
        	 cin>>x;
        	 if(x>0)
        	 	pre+=x;
        }
        cout<<pre<<endl;
      
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