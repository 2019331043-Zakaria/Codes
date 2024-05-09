/*
* @Author: Zakaria
* @Date:   2023-01-13 16:32:05
* @Last Modified time: 2023-01-13 16:52:03
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

short int dp[505][505][505];  // index, cur_sum, k
int a[505];
int vis[505];
int n, k;

int foo(int index, int cur_sum, int total_sum)
{
	if (total_sum > k)
		return 0;

	if (index == n)
	{
		if (total_sum == k)
		{
			vis[cur_sum] = 1;
			return 1;
		}
		else
			return 0;
	}

	auto &R = dp[index][cur_sum][total_sum];

	if (R != -1)
		return R;

	R = (foo(index + 1, cur_sum, total_sum) |
	     foo(index + 1, cur_sum, total_sum + a[index]) |
	     foo(index + 1, cur_sum + a[index], total_sum + a[index]));

	if (R)
		vis[cur_sum] = 1;

	return R;

}

void Solve()
{

	cin >> n >> k;

	for (int i = 0 ; i < n ; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));

	foo(0, 0, 0);

	vector<int>ans;

	for (int i = 0 ; i <= k ; i++)
	{
		if (vis[i]) ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << " ";
	cout << endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//   cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}