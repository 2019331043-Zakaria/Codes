/*
* @Author: Zakaria
* @Date:   2023-01-14 00:08:36
* @Last Modified time: 2023-01-14 01:05:04
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

int a[N];
int n;
int dp[5004][5004];
vector<int>v;

int foo(int l, int r)
{

	if (l == r)
		return 0;

	int &R = dp[l][r];

	if (~R)
		return R;

	R = INT_MAX;

	if (v[l] == v[r])
		R = min(R, foo(l + 1, r - 1) + 1);
	else
	{
		R = min(R, foo(l + 1, r) + 1);
		R = min(R, foo(l, r - 1) + 1);
	}

	return R;

}

void Solve()
{


	cin >> n;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));

	v.push_back(a[1]);

	for (int i = 2 ; i <= n ; i++)
		if (a[i] != v.back())
			v.push_back(a[i]);



	cout << foo(0, v.size() - 1) << endl;



}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}