#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[205][13];

ll ncr(ll n, ll r)
{
	  if(n==r)
	  	return dp[n][r]=1;
	  if(r==0)
	  	return dp[n][r]=0;
	  if(r==1)
	  	return dp[n][r]=n;
	  if(dp[n][r])
	  	return dp[n][r];
	  
	  return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
}


int main()
{ 

	  int n,r;
	  cin>>n>>r;
	  cout<<ncr(n,r)<<endl;

}