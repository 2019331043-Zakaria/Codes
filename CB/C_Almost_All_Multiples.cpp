/*
* @Author: Zakaria 
* @Date:   2022-11-25 22:37:40
* @Last Modified time: 2022-11-26 00:39:47
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
        
        ll n, m;
        cin>>n>>m;

        if(n%m)
        {
        	cout<<-1<<endl;
        }
        else
        {
        	int a[n+1];
        	a[1] = m;

            a[n] = 1;
        	for(int i=2 ; i<n ; i++)
            {
                  if(i==m)
                  	a[i] = n;
                  else
                  	a[i] = i;
            }
            
            for(int i=2 ; i<n ; i++)
            {
            	if(i%m==0 && n%i==0)
            	{
                    swap(a[i], a[m]);
                    m = i;
            	}
            }

            for(int i=1 ; i<=n ; i++)
            	cout<<a[i]<<" ";

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