/*
* @Author: Zakaria
* @Date:   2023-01-13 11:58:34
* @Last Modified time: 2023-01-13 14:52:54
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

const int mod = 998244353 ;
const int N = 1000 + 6;
ll dp[N][N + N][4];

ll foo(int pos, int compo, int type)
{


	if (pos == 1)
	{
		if (type == 0 || type == 3)
			compo--;
		if (type == 1 || type == 2)
			compo -= 2;

		if (compo == 0)
			return 1;
		else
			return 0;
	}

	ll &R = dp[pos][compo][type];

	if (R != -1)
		return R;

	R = 0;

	if (type == 0)
	{
		R += foo(pos - 1, compo, 0);
		R %= mod;
		R += foo(pos - 1, compo, 1);
		R %= mod;
		R += foo(pos - 1, compo, 2);
		R += mod;
		R += foo(pos - 1, compo - 1, 3);
		R %= mod;

	}
	if (type == 1)
	{
		R += foo(pos - 1, compo - 1, 0);
		R %= mod;
		R += foo(pos - 1, compo, 1);
		R %= mod;
		R += foo(pos - 1, compo - 2, 2);
		R += mod;
		R += foo(pos - 1, compo - 1, 3);
		R %= mod;
	}
	if (type == 2)
	{
		R += foo(pos - 1, compo - 1, 0);
		R %= mod;
		R += foo(pos - 1, compo - 2, 1);
		R %= mod;
		R += foo(pos - 1, compo, 2);
		R += mod;
		R += foo(pos - 1, compo - 1, 3);
		R %= mod;
	}
	if (type == 3)
	{
		R += foo(pos - 1, compo - 1, 0);
		R %= mod;
		R += foo(pos - 1, compo, 1);
		R %= mod;
		R += foo(pos - 1, compo, 2);
		R += mod;
		R += foo(pos - 1, compo, 3);
		R %= mod;
	}

	return R;


}

void Solve()
{


	memset(dp, -1, sizeof(dp));

	int n, k;
	cin >> n >> k;

	ll ans = 0;

	ans += foo(n, k, 0);
	ans %= mod;
	ans += foo(n, k, 1);
	ans %= mod;
	ans += foo(n, k, 2);
	ans %= mod;
	ans += foo(n, k, 3);
	ans %= mod;

	cout << ans << endl;

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