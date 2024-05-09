/*
* @Author: Zakaria
* @Date:   2023-03-19 17:54:28
* @Last Modified time: 2023-03-19 18:05:07
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

struct edge
{
	ll u, v, w;
};


bool comp(edge a, edge b)
{
	return a.w < b.w;
}

int n, m;

ll Parent[N], Rank[N];

void Init(int n)
{
	for (int i = 1 ; i <= n ; i++)
		Rank[i] = 1, Parent[i] = i;
}

int Find_Parent(int v)
{
	if (v == Parent[v])
		return v;

	return Parent[v] = Find_Parent(Parent[v]);
}

void Union(int a, int b)
{
	a = Find_Parent(a);
	b = Find_Parent(b);

	if (a != b)
	{

		if (Rank[a] > Rank[b])
			swap (a, b);

		Parent[a] = b;
		Rank[b] += Rank[a];
	}
}



void Solve()
{
	cin >> n;

	vector<edge>v;

	for (int i = 1 ; i < n ; i++)
	{
		edge x;
		cin >> x.u >> x.v >> x.w;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), comp );

	Init(n);

	ll ans = 0;

	for (auto i : v)
	{

		if (Find_Parent(i.u) == Find_Parent(i.v))
		{
			ans = ans + 1LL * Rank[Find_Parent(i.u)] * i.w;
		}
		else
			ans = ans + 1LL * Rank[Find_Parent(i.u)] * Rank[Find_Parent(i.v)] * i.w;

		Union(i.u, i.v);
	}

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