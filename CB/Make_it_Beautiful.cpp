/*
* @Author: Zakaria 
* @Date:   2023-01-08 20:37:04
* @Last Modified time: 2023-01-08 20:39:02
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

        int a[n];

        for(int i=0 ; i<n ; i++)
        	cin>>a[i];

        sort(a, a+n);

        reverse(a, a+n);

        int sum=0;

        for(auto i:a)
        {
        	if(i==sum)
        	{
        		cout<<"NO"<<endl;
        		reverse ;
        	}
        	sum+=i;
        }

        cout<<"YES"<<endl;
        for(auto i:a)
        	cout<<i<<" ";

        cout<<endl;
      
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