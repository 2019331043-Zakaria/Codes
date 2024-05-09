/*
* @Author: Zakaria
* @Date:   2023-02-20 19:43:29
* @Last Modified time: 2023-02-20 19:53:42
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

const int mod = 998244353;
const int N = 2e5 + 6;


ll dp[105][105][105];

int a[N], b[N];
int n;

ll foo(int index, int cursum, int done, int k)
{
	if (index > n || done < 0)
		return 0;

	if (cursum == 0 && done == 0)
		return 1;

	ll &R = dp[index][cursum][done];

	if (R != -1)
		return R;

	return R = (foo(index + 1, (cursum + a[index]) % k, done - 1, k) + foo(index + 1, cursum, done, k)) % mod;


}

void Solve()
{

	cin >> n;

	for (int i = 0 ; i < n ; i++)
		cin >> b[i];

	ll ans = 0;
	for (int k = 1 ; k <= n ; k++)
	{
		for (int j = 0; j < n ; j++)
			a[j] = b[j] % k;

		memset(dp, -1, sizeof(dp));

		ans += foo(0, 0, k, k);
		ans %= mod;
	}

	cout << ans << endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//  cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}