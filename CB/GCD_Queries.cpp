/*
* @Author: Zakaria
* @Date:   2023-04-12 21:02:44
* @Last Modified time: 2023-04-12 22:01:20
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
const int N = 2e6 + 6;

#define sz 10000010
bool siv[sz];
int spf[sz];

void seive()
{
	int  limit = sqrt(sz + 1);

	for (int i = 1 ; i < sz ; i++)
		spf[i] = i;

	for (int i = 2 ; i < sz ; i += 2)
		spf[i] = 2;

	for (int  i = 3; i <= limit; i += 2)
		if (!siv[i])
			for (int  j = i * i; j < sz; j += i + i)
				siv[j] = 1, spf[j] = min(spf[j], i);
}

set<int> generatefact(int x)
{
	set<int>fact;

	while (x > 1)
	{
		fact.insert(spf[x]);
		x /= spf[x];
	}

	return fact;
}

void Solve()
{

	int n;
	cin >> n;

	int a[n];

	multiset<int>st;
	map<int, multiset<int> > node;

	for (int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		st.insert(a[i]);

		set<int>fact;
		fact = generatefact(a[i]);
		for (auto k : fact)
			node[k].insert(a[i]);


	}

	int q;
	cin >> q;

	while (q--)
	{
		int x;
		cin >> x;


		set<int>fact;

		fact = generatefact(x);

		int ans = 1e9;
		

		for (auto i : fact)
		{
			if (node[i].size())
			{
				int val = *node[i].begin();
				ans = min(ans, val);
			}
		}

		if (ans == 1e9)
			ans = *st.begin();

		cout << ans << " ";

		fact = generatefact(ans);

		for (auto k : fact)
		{
			if (node[k].size())
				node[k].erase(node[k].find(ans));
		}

		st.erase(st.find(ans));
	}

	cout << endl;




}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	seive();

	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}