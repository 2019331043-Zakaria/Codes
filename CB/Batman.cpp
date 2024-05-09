/*
* @Author: Zakaria
* @Date:   2023-02-20 23:51:38
* @Last Modified time: 2023-02-21 00:16:52
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

int dp[55][55][55];

string s, t, u;
int x, y, z;


int foo(int i, int j, int k)
{
	
	if (i == x || j == y || k == z)
		return 0;

	int &R = dp[i][j][k];

	if (R != -1)
		return R;

	if (s[i] == t[j] && t[j] == u[k])
	{
		return R = 1 + foo(i+1, j+1, k+1);
	}
	else
	{
		return R = max({foo(i+1, j, k), foo(i, j+1, k), foo(i, j, k+1)});
	}
}

void Solve()
{

	memset(dp, -1, sizeof(dp));
	cin >> s >> t >> u;

	x = s.size();
	y = t.size();
	z = u.size();

	cout << foo(0, 0, 0) << endl;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	cin >> tt;

	int t = 1;
	while (tt--)
	{
        cout<<"Case "<<t++<<": ";
		Solve();
	}

	return 0;

}