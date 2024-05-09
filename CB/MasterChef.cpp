/*
* @Author: Zakaria
* @Date:   2023-04-18 21:47:16
* @Last Modified time: 2023-04-19 01:24:49
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

ll n, m, k;
ll sum[N];
vector<pair<ll, ll> > L[N];
vector<ll>R[N];
ll cost[N];
ll dp[504];

// ll foo(int index, int rem)
// {
// 	if (index > n)
// 		return 0;

// 	ll &R = dp[index][rem];

// 	if (R != -1)
// 		return R;

// 	R = 1e18;

// 	R = min(R, foo(index + 1, rem));

// 	if (cost[index] <= rem)
// 		R = min(R, sum[index] + foo(index + 1, rem - cost[index]));


// 	return R;
// }
void Solve()
{

	cin >> n >> k >> m;

	ll tot = 0;

	for (int i = 1 ; i <= n ; i++)
		cin >> sum[i], tot += sum[i], cost[i] = 1e18, L[i].clear(), R[i].clear(), cost[i] = 1e18;

	ll neg = 0;

	for (int i = 0 ; i < m ; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;

		L[l].push_back({c, r});
		R[r].push_back(c);
	}

	set<pair<ll, ll > > st;

	for (int i = 1 ; i <= n ; i++)
	{
		for (auto p : L[i])
			st.insert(p);
		if (st.size())
			cost[i] = (*st.begin()).f;

		for (auto p : R[i])
			st.erase({p, i});
	}

	memset(dp, 0, sizeof(dp));

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=k ; j>0 ; j--)
		{
			dp[j] = min(dp[j], dp[j-1]);

			if(cost[i]<=j)
			{
				dp[j] = min(dp[j], dp[j - cost[i]] + sum[i]);
			}
		}
	}

	cout << tot - dp[k] << endl;




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