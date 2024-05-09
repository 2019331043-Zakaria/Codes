/*
* @Author: Zakaria 
* @Date:   2022-09-30 21:59:39
* @Last Modified time: 2022-10-01 01:52:32
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

int dp[103][103][2][2];

int foo(int even, int odd, int sum_parity, int alice)
{
        int &R = dp[even][odd][sum_parity][alice];
        
        if(even==0 && odd==0)
        {
              if(sum_parity) //sum even
              {
              	  if(alice)
              	  	return R = 1;
              	  else
              	  	return R = 0;
              }
              if(alice)
              	return R = 0;
              else
              	return R = 1;
        }

        if(~R)
        	return R;

        int a=0, b=0;

        if(alice)
        {   
            // alice
        	if(even>0)
        		a = !foo(even-1, odd, sum_parity, !alice);
        	if(odd>0)
        		b = !foo(even, odd - 1, !sum_parity, !alice);
        }
        else
        {
        	//bob
        	if(even>0)
        		a = !foo(even -1 , odd, sum_parity, !alice);
        	if(odd>0)
        		b = !foo(even , odd - 1, sum_parity, !alice); 
        }

        return R = max(a, b);


     	  
}

void Solve()
{
       int n;
       cin>>n;

       int odd=0, even=0;

       for(int i=1 ; i<=n ; i++)
       {
       	  int x;
       	  cin>>x;
       	  x=abs(x);

       	  if(x%2)
       	  	odd++;
       	  else
       	  	even++;
       }

       memset(dp, -1, sizeof(dp));

       if(foo(even, odd, 1, 1))
       	cout<<"Alice"<<endl;
       else
       	cout<<"Bob"<<endl;
      
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