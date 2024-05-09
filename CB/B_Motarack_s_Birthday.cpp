/*
* @Author: Zakaria
* @Date:   2023-03-28 01:13:08
* @Last Modified time: 2023-03-28 01:42:50
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

	ll a[n];

	for (int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}

	ll mx = 0, mn = 1e18;

	for (int i = 0 ; i < n ; i++)
	{
		if (a[i] == -1)
		{
			if (i == 0)
			{
				if (~a[i + 1])
					mx = max(mx, a[i + 1]), mn = min(mn, a[i + 1]);
			}
			else if (i == n - 1)
			{
				if (~a[i - 1])
					mx = max(mx, a[i - 1]), mn = min(mn, a[i - 1]);
			}
			else
			{
				if (~a[i + 1])
					mx = max(mx, a[i + 1]), mn = min(mn, a[i + 1]);
				if (~a[i - 1])
					mx = max(mx, a[i - 1]), mn = min(mn, a[i - 1]);
			}
		}
	}

	if (mn==1e18)
	{
		cout << 0 << " " << 0 << endl;
		return ;
	}

	ll missing = (mx + mn)/2;

	for(int i=0 ; i<n ; i++)
		if(a[i]==-1)
			a[i] = missing;

	ll ans = 0;

	for (int i = 1 ; i < n ; i++)
		ans = max(ans, abs(a[i] - a[i - 1]));

	cout << ans << " " << missing << endl;

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