/*
* @Author: Zakaria 
* @Date:   2022-10-10 12:43:14
* @Last Modified time: 2022-10-10 15:48:33
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

int n, k;
vector<pair<int , int> > v;
int dp[205][205][200];

pair<int, int>yo(ll x)
{
	   int cnt2=0;

	   while(x%2==0)
	   	cnt2++, x/=2;


	   int cnt5=0;

	   while(x%5==0)
	   	cnt5++, x/=5;

	   return {cnt2, cnt5};
}

int foo(int i, int j, int five)
{

	   
	   if(j>k)
	   	return 0;
       
       if(i==n)
       	return 0;

       if(five<0)
       	return 0;

	   int &R = dp[i][j][five];

	   if(R!=-1)
	   	return R;

	   R = 0;
       
       return R = max( v[i].f + foo(i+1, j+1, five - v[i].s), foo(i+1, j, five));
	   
}


void Solve()
{
        
         
         cin>>n>>k;

         for(int i=0 ; i<n ; i++)
         {
         	 ll x;
         	 cin>>x;
         	 v.push_back({yo(x)});
         }

         memset(dp, -1, sizeof(dp));

         dp[0][0][0] = 0;

         foo(0, 0, 100);

         

        
      
}
 
int main()
{
         
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int tt=1;
        
     //   cin>>tt;
        
        while(tt--)
        {
           
            Solve();
        }
 
        return 0;
        
} 