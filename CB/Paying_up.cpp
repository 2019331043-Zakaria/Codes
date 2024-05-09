/*
* @Author: Zakaria 
* @Date:   2023-04-17 23:30:17
* @Last Modified time: 2023-04-17 23:34:57
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

int dp[22][30000];
int n, k;
int a[N];

bool foo(int index, int sum)
{
	  if(index==n)
	  {
	  	  return sum==k;
	  }

	  int &R = dp[index][sum];

	  if(R!=-1)
	  	return R;

	  return R = foo(index+1, sum) | foo(index+1, sum+a[index]);
}

void Solve()
{
        
       memset(dp, -1, sizeof(dp));
       cin>>n>>k;

       for(int i=0 ; i<n ; i++)
       	cin>>a[i];


       if(foo(0, 0))
       {
       	  cout<<"Yes"<<endl;
       }
       else
       	cout<<"No"<<endl;

      
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