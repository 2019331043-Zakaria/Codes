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

string s[N];
ll CalculateMask[N], CalculateCommask[N];

void Solve()
{

	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i++)
	{
		cin >> s[i];

		int bit[30] {};
		
		for (auto c : s[i])
			bit[c - 'a'] ^= 1;

		ll mask = 0;
		ll complemask = 0;

		for (char c = 'a' ; c <= 'z' ; c++)
		{
			int p = c - 'a';
			if (bit[p])
			{
				mask += 1LL << p;
			}
			else
			{
				complemask += 1LL << p;
			}
		}

		CalculateMask[i] = mask;
		CalculateCommask[i] = complemask;
	}

	ll ans = 0;

	for (char c = 'a' ; c <= 'z' ; c++)
	{
		vector<int>index;

		for (int i = 0 ; i < n ; i++)
		{
			bool ok = 0;
			for (auto k : s[i])
				ok |= (k == c);

			if (!ok)
				index.push_back(i);
		}

		map<ll, ll> cnt;

		for (auto i : index)
		{
			ll temp = c - 'a';

			temp = 1LL << temp;

			ll mask = CalculateMask[i];
			ll complemask = CalculateCommask[i] - temp;

			ans += cnt[complemask];
			cnt[mask]++;
		}

	}

	cout << ans << endl;

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	// cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}