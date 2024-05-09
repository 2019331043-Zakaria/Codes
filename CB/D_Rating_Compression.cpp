/*
* @Author: Zakaria
* @Date:   2023-01-12 23:19:56
* @Last Modified time: 2023-01-12 23:36:52
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
const int N = 5e5 + 9;

int Table[N][20], a[N];
int n;

void Build(int n)
{

	for (int i = 1 ; i <= n ; i++)
		Table[i][0] = a[i];

	for (int k = 1 ; k < 20 ; k++)
	{
		for (int i = 1 ; i + (1 << k) - 1 <= n ; i++)
			Table[i][k] = min(Table[i][k - 1], Table[i + (1 << (k - 1))][k - 1]);
	}

}

int Query(int l, int r)
{
	int k = log2(r - l + 1);
	return min(Table[l][k], Table[r - (1 << k) + 1][k]);
}

bool Check(int mid)
{
	vector<int>v;

	for (int i = 1 ; i <= n - mid + 1 ; i++)
	{
		v.push_back(Query(i, i + mid - 1));
	}

	sort(v.rbegin(), v.rend());

	for (int i = 1 ; i <= n - mid + 1 ; i++)
	{
		if (i != v.back())
			return 1;
		v.pop_back();
	}

	return 0;


}

void Solve()
{


	cin >> n;

	set<int>st;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i], st.insert(a[i]);

	Build(n);

	int ans[n + 1];

	if (st.size() == n)
		ans[1] = 1;
	else
		ans[1] = 0;


	int low = 2, high = n, mid;
	int result = 1;

	while (low <= high)
	{
		mid = (low + high) >> 1;

		if (Check(mid))
			result = mid, low = mid + 1;
		else
			high = mid - 1;
	}

	for (int i = 2  ; i <= result ; i++)
		ans[i] = 0;

	for (int i = result + 1 ; i <= n ; i++)
		ans[i] = 1;

	for (int i = 1 ; i <= n ; i++)
		cout << ans[i];

	cout << endl;






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