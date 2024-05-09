/*
* @Author: Zakaria 
* @Date:   2022-10-26 21:36:54
* @Last Modified time: 2022-10-26 21:39:05
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

        for(ll i = 0 ; i*i<=n ; i++)
        {
        	ll a = i;
        	
        	ll baki = n - i*i;
            
            ll temp = sqrtl(baki);

            if(temp*temp==baki)
            {
            	cout<<i<<" "<<temp<<endl;
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
        
        cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 