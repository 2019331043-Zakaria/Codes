/*
* @Author: Zakaria 
* @Date:   2022-12-21 18:46:38
* @Last Modified time: 2022-12-21 18:49:35
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

        ll a[n];

        for(int i = 0 ; i<n ; i++)
        	cin>>a[i];

        ll temp = 0;

        for(int i=1 ; i<n ; i++)
        {
        	if(a[i]<a[i-1])
        	{
        		temp = max(temp, a[i]+a[i-1]);
        	}
        }

        temp = (temp+1)/2;

        for(int i = 0 ; i<n ; i++)
        	a[i]-=temp, a[i] = abs(a[i]);

        if(is_sorted(a, a+n))
        	cout<<temp<<endl;
        else
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