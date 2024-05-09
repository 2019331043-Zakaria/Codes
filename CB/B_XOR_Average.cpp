/*
* @Author: Zakaria 
* @Date:   2022-11-25 21:38:19
* @Last Modified time: 2022-11-25 22:36:31
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

        if(n%2)
        {
        	for(int i=1 ; i<=n ; i++)
        		cout<<1<<" ";
        	cout<<endl;
        }
        else
        {
        	cout<<1<<" ";

        	for(int i=1 ; i<n ; i++)
        		cout<<n+1<<" ";

        	cout<<endl;

        }
      
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