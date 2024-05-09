/*
* @Author: Zakaria
* @Date:   2023-01-30 11:50:55
* @Last Modified time: 2023-01-30 11:56:55
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

	map<int, int>m;

	for (int i = 1 ; i <= n ; i++)
	{
		int x;
		cin >> x;
		m[x]++;
	}

	priority_queue<int>pq;

	for (auto i : m)
		pq.push(i.s), cout << i.f << " " << i.s << endl;


	int ans = 0;
	int last = 1e9;

	while (pq.size() && last >= 1)
	{
		int val = pq.top();

		pq.pop();

		if (val == last)
		{
			ans++;
			last--;
			pq.push(1);
		}
		else
		{
			ans++;
			last = val;
		}
	}

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