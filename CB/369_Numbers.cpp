/*
* @Author: Zakaria
* @Date:   2023-04-11 23:12:03
* @Last Modified time: 2023-04-12 02:00:00
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

const int mod = 1000000007;
const int N = 2e5 + 6;

string s;
ll dp[51][17][17][17][2]; //pos, three , six , nine, bool


ll foo(int pos, int three, int six , int nine,  bool ok)
{

	if (three >= 17 || six >= 17 || nine >= 17)
		return 0;

	if (pos == s.size())
	{
		return three == six && six == nine && three;
	}

	ll &R = dp[pos][three][six][nine][ok];

	if (R != -1)
		return R;

	ll res = 0;

	int maxdigit = 9;

	if (!ok)
		maxdigit = s[pos] - '0';

	for (int i = 0 ; i <= maxdigit ; i++)
	{

		if (i < maxdigit || ok)
			res += foo(pos + 1, three + (i == 3), six + (i == 6), nine + (i == 9), true);
		else
			res += foo(pos + 1, three + (i == 3), six + (i == 6), nine + (i == 9), false);

		res %= mod;
	}
	return R = res;
}

void Solve()
{

	string l, r;
	cin >> l >> r;

	ll ans = 0;

	s = r;
	memset(dp, -1, sizeof(dp));
	ans += foo(0, 0, 0, 0, 0);
	ans %= mod;

	s = l;
	memset(dp, -1, sizeof(dp));
	ans -= foo(0, 0, 0, 0, 0);
	ans += mod;
	ans %= mod;

	int three = 0, six = 0, nine = 0;

	for (auto i : s)
	{
		three += (i == '3');
		six += (i == '6');
		nine += (i == '9');
	}

	if (three && three == six && six == nine)
		ans++;
	ans %= mod;

	cout << ans << endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	cin >> tt;

	int cs = 1;

	while (tt--)
	{

		Solve();
	}

	return 0;

}