/*
* @Author: Zakaria
* @Date:   2023-02-21 00:59:10
* @Last Modified time: 2023-02-21 01:04:21
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


ll fact[200008];

ll bigmod(ll b, ll p)
{
	if (p == 0) return 1;
	ll h = bigmod(b, p / 2);
	h = h * h % mod;
	if (p & 1) h = h * b % mod;
	return h;
}

ll ncr(ll n, ll r)
{
	if (n < r)
		return 0;
	return fact[n] * bigmod(fact[r] * fact[n - r] % mod, mod - 2) % mod;
}

void Fact()
{
	fact[0] = 1;
	for (int i = 1; i <= 200002; i++) fact[i] = fact[i - 1] * i % mod;
}


void Solve()
{

	Fact();

	int n;
	cin >> n;

	ll ans = ncr(n / 3, n / 6);

	n /= 3;

	for (int i = 1 ; i <= n ; i++)
	{
		int a[3];
		cin >> a[0] >> a[1] >> a[2];

		sort(a, a + 3);

		if (a[0] == a[1] && a[1] == a[2])
			ans *= 3LL, ans %= mod;
		else if (a[0] == a[1] && a[1] != a[2])
			ans *= 2LL, ans %= mod;
		else
			ans = ans;
	}

	cout<<ans<<endl;


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