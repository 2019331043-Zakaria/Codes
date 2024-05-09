#include <bits/stdc++.h>
using namespace std;

int w, n;
int weight[2005];
int profit[2005];
int dp[2005][2005];

int knapsack(int index, int remain)
{
	if(index==n+1)
		return 0;

	if(dp[index][remain]!=-1)
		return dp[index][remain];

	int niye = 0;

	if(weight[index]<=remain)
		niye = profit[index] + knapsack(index+1, remain - weight[index]);

	int na_niye = 0;

	na_niye = 0 + knapsack(index+1, remain);

	dp[index][remain] = max(niye, na_niye);

	return dp[index][remain];

}

int main()
{
      
      cin>>w>>n;

      for(int i=1 ; i<=n ; i++)
      {
      	  cin>>weight[i]>>profit[i];
      }

      for(int i=0 ; i<=n ; i++)
      {
      	for(int j=0 ; j<=w ; j++)
      	{
      		dp[i][j] = -1;
      	}
      }

    //  memset(dp, -1, sizeof(dp));

      int ans = knapsack(1, w);

      cout<<ans<<endl;


      return 0;
}