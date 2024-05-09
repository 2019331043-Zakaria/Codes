/*
* @Author: Zakaria 
* @Date:   2023-03-04 23:53:09
* @Last Modified time: 2023-03-05 00:04:14
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

      for(int i=1 ; i<=n ; i++)
      {
      	if(a[i]==1)
      		a[i]++;
      }

      vector<int>ans;

      for(int i=2 ; i<=n ; i++)
      {
      	 
      	 if(a[i]%a[i-1]==0)
      	 	a[i]++;
      }

      for(int i=1 ; i<=n ; i++)
      	cout<<a[i]<<" ";
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