/*
* @Author: Zakaria 
* @Date:   2023-04-23 22:19:13
* @Last Modified time: 2023-04-24 00:05:01
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


int a[100];
int n, k;
int dp[65][65][65];  // index, k, ith index vis or not

int foo(int index, int rem)
{
	

	int &r = dp[index][rem];

	if(r!=-1)
		return

}

void Solve()
{
        
      cin>>n>>k;

      for(int i=0 ; i<n ; i++)
      {
      	  cin>>a[i];
      }

      foo(0, 0);

      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
    //    cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 