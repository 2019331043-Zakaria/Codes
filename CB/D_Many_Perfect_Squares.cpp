/*
* @Author: Zakaria
* @Date:   2023-01-18 22:13:12
* @Last Modified time: 2023-01-18 23:14:03
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

	int n;
	cin >> n;

	ll a[n + 1];

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];

	map<ll, set<int> > cnt;

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = i + 1 ; j <= n ; j++)
		{
			ll D = a[j] - a[i];

			for (ll div = 1 ; div * div <= D ; div++)
			{
				if (D % div == 0)
				{
					ll uMinusv = div;
					ll uPLUSv = D / div;

					if ((uMinusv + uPLUSv) % 2)
						continue;
					ll u = (uMinusv + uPLUSv) / 2;
					ll v = (uPLUSv - uMinusv) / 2;

					u = u * u;

					if (u < a[j])
						continue;

					cnt[u - a[j]].insert(i);
					cnt[u - a[j]].insert(j);
				}
			}
		}
	}

	int ans = 1;

	for (auto i : cnt)
		ans = max(ans, (int) i.s.size());

	cout << ans << endl;


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