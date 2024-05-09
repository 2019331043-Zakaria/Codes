/*
* @Author: Zakaria 
* @Date:   2022-10-02 10:37:42
* @Last Modified time: 2022-10-02 10:56:32
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
        
      
        int n, m;
        cin>>n>>m;

        if(m<n)
        {
        	cout<<"NO"<<endl;
        	return ;
        }

        if(n%2)
        {
        	cout<<"YES"<<endl;
        	for(int i=1 ; i<n ; i++)
        		cout<<1<<" ";
        	cout<<m-n+1<<endl;
        }
        else
        {
        	if(m%2)
        		cout<<"NO"<<endl;
        	else
        	{
        		cout<<"YES"<<endl;
        		for(int i=1 ; i<=n-2 ; i++)
        			cout<<1<<" ";
        		int rem=m-(n-2);
        		cout<<rem/2<<" "<<rem/2<<endl;
        	}
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