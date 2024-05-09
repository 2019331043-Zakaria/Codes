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

	int a[n + 1];

	int pos[n + 1];


	set<int>st;


	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		st.insert(i);

	}
	int b[n + 1];

	for (int i = 1 ; i <= n ; i++)
	{
		cin >> b[i];
		pos[b[i]] = i;
	}

	int l = 1;

	set<int>ans;


	for (int i = 1 ; i <= n ; i++)
	{
		int index = pos[a[i]];

		for (int j = index - 1 ; j >= l ; j--)
		{
			if (st.find(b[j]) != st.end())
			{
				ans.insert(b[j]);
			}
		}

		l = max(l, index);

		st.erase(a[i]);
	}


	cout << (int) ans.size() << endl;

	for (auto i : ans)
		cout << i << " ";
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