/*
* @Author: Zakaria 
* @Date:   2022-10-22 16:27:46
* @Last Modified time: 2022-10-22 17:36:43
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

        int a[n+1];
       

        for(int i=0 ; i<n ; i++)
        	cin>>a[i];
        
        a[n]=-1;
       
        int x = -1, y = -1;

        int ans = 0;

        for(int i = 0 ; i<n ; i++)
        {
        	if(x==a[i] && y==a[i])
        		continue;
        	else if(x==a[i]) 
        		ans++, y = a[i];
        	else if(y==a[i])
        		ans++, x = a[i];
        	else
        	{
        		if(a[i+1]==x)
        			ans++, x = a[i];
        		else
        			ans++, y = a[i];
        	}
        }

        cout<<ans<<endl;
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
      //  cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 