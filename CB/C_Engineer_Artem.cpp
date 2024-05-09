/*
* @Author: Zakaria
* @Date:   2023-04-13 22:36:05
* @Last Modified time: 2023-04-13 22:48:17
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
const int N = 2e5 + 6;

void Solve()
{

	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > parity[2];

	int a[n + 1][m + 1];

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			parity[(i + j) % 2].push_back({i, j});
		}
	}

	// even->even, odd->odd
	int cnt1 = 0;
	for (auto [x, y] : parity[0])
	{
		if (a[x][y] % 2)
			cnt1++;
	}

	for (auto [x, y] : parity[1])
	{
		if (a[x][y] % 2 == 0)
			cnt1++;
	}

	// even -> odd, odd->even;

	int cnt2 = 0;
	for (auto [x, y] : parity[0])
	{
		if (a[x][y] % 2 == 0)
			cnt2++;
	}

	for (auto [x, y] : parity[1])
	{
		if (a[x][y] % 2)
			cnt2++;
	}

	if (cnt1 < cnt2)
	{
		for (auto [x, y] : parity[0])
		{
			a[x][y] += (a[x][y] % 2);
		}

		for (auto [x, y] : parity[1])
		{
			a[x][y] += !(a[x][y] % 2);
		}
	}
	else
	{
		for (auto [x, y] : parity[0])
		{
			a[x][y] += !(a[x][y] % 2);
		}

		for (auto [x, y] : parity[1])
		{
			a[x][y] += (a[x][y] % 2);
		}
	}

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}


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