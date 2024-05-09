/*
* @Author: Zakaria 
* @Date:   2022-10-10 15:48:23
* @Last Modified time: 2022-10-10 17:18:22
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

int dp[3050][1020];
int a[N];
int n, k;

int can(int i, int temp)
{
	  if(temp==0)
	  	return 1;
	  if(i==n)
	  	return 0;

	  int &R = dp[i][temp];

	  if(R!=-1)
	  	return R;

	  return R = (can(i+1, (temp - a[i] +k)%k) || can(i+1, temp) );
}

void Solve()
{
        
      
        cin>>n>>k;

     
       
        for(int i=0 ; i<n ; i++)
          cin>>a[i], a[i]%=k;

        if(n>k)
        {
        	cout<<"YES"<<endl;
        	return ;
        }

        memset(dp, -1, sizeof(dp));

        if(can(0, k))
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;

        
        

      
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