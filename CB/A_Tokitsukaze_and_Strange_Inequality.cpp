/*
* @Author: Zakaria
* @Date:   2023-04-12 16:54:14
* @Last Modified time: 2023-04-12 18:48:57
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

const int mod = 1e9 + 7;
const int N = 5005;

int dpleft[N][N], dpright[N][N];
int a[N];

void Solve()
{

	int n;
	cin >> n;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];


    
	ll ans = 0;
	for (int j = 1 ; j <= n ; j++)
	{
		for (int i = 1 ; i <= j ; i++)
		{
			dpleft[i][j] = dpleft[i-1][j];

			if(a[i]<a[j])
				dpleft[i][j]++;
		}
	}

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=n ; j>=i ; j--)
		{
			dpright[i][j] = dpright[i][j+1];
			if(a[i]>a[j])
				dpright[i][j]++;

		}
	}


	for (int i = 2 ; i < n ; i++)
	{
		for (int j = n ; j > i ; j--)
		{
			// for leftdp we need how many number a[1.....i-1]<a[j]
			// for rightdp we need how many number a[i]>a[j+1.....n]
			// cout<<i<<" "<<j<<" > ";
			// cout<<dpleft[i-1][j]<<" "<<dpright[i][j+1]<<endl;
			ans+=(dpleft[i-1][j] * dpright[i][j+1]);
		}
	}

	for(int i=1 ; i<=n ; i++)
	{
		 for(int j=1 ; j<=n ; j++)
		 	dpleft[i][j] =0, dpright[i][j] = 0;
	}
	
	cout<<ans<<endl;


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}