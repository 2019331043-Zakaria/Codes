/*
* @Author: Zakaria
* @Date:   2023-03-24 23:06:54
* @Last Modified time: 2023-03-24 23:33:25
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

const ll op1 = 1e12 + 1;
const ll op2 = 1e12;


void Solve()
{


	string s;
	cin >> s;

	ll n = s.size();

	s = '*' + s;

	ll prefzero[n + 5], suffzero[n + 5], prefone[n + 5], suffone[n + 5];

	for (int i = 0 ; i <= n + 2 ; i++)
		prefzero[i] = 0, suffzero[i] = 0, prefone[i] = 0, suffone[i] = 0;

	for (int i = 1 ; i <= n ; i++)
	{
		prefzero[i] = (s[i] == '0');
		prefzero[i] += prefzero[i - 1];

		prefone[i] = (s[i] == '1');
		prefone[i] += prefone[i - 1];
	}

	suffzero[n + 1] = 0;

	for (int i = n ; i >= 1 ; i--)
	{
		suffzero[i] = s[i] == '0';
		suffzero[i] += suffzero[i + 1];

		suffone[i] = (s[i] == '1');
		suffone[i] += suffone[i + 1];
	}

	ll ans = min(prefzero[n], prefone[n]) * op1;

	if (n == 1)
	{
		cout << 0 << endl;
		return ;
	}

	for (int i = 1 ; i <= n ; i++)
	{

		if (i < n && s[i] == '1' && s[i + 1] == '0')
		{
			ans = min(ans, op2 + (prefone[i] - 1 + suffzero[i + 1] - 1) * op1);
		}
		ans = min(ans, (prefone[i] + suffzero[i + 1]) * op1); //01
	}

	cout<<ans<<endl;

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