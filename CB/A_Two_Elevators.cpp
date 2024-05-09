/*
* @Author: Zakaria 
* @Date:   2022-09-12 20:35:21
* @Last Modified time: 2022-09-12 20:40:10
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
        
        ll a, b, c;
        cin>>a>>b>>c;

        ll ans1=a-1;
        
        ll ans2=0;
        if(c>=b)
        	ans2 = c-b+c-1;
        else
        	ans2 = b-1;
       
       if(ans1<ans2)
       	cout<<1<<endl;
       else if(ans2<ans1)
       	cout<<2<<endl;
       else
       	cout<<3<<endl;
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