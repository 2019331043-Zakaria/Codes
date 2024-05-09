/*
* @Author: Zakaria 
* @Date:   2022-10-26 20:38:08
* @Last Modified time: 2022-10-26 20:54:16
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
        
        int n, q;
        cin>>n>>q;

        ll a[n+5];
        
        memset(a, 0, sizeof(a));

        ll sum=0;

        for(int i=1 ; i<=n ; i++)
        	cin>>a[i], sum+=a[i];

      /*  for(int i=1 ; i<=n ; i++)
        	cout<<a[i]<<" ";
        cout<<endl;*/
       

        while(q--)
        {
        	int l, r;
        	cin>>l>>r;
        	

        	ll len = (r - l + 1);
            
            if(len%2)
            {
            	sum+=(len+1)/2;
            	sum-=(len)/2;
            }
            
        	
        }

        cout<<sum<<endl;

       
      
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