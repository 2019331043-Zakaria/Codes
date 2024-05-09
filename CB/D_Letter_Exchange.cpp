/*
* @Author: Zakaria
* @Date:   2023-02-05 20:31:22
* @Last Modified time: 2023-02-06 15:12:32
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

	string s[n];

	for (int i = 0 ; i < n ; i++)
		cin >> s[i];

	map<pair<char, char>, vector<int> > boro, choto;

	char fw = 'w', fi = 'i', fn = 'n';

	for (int i = 0 ; i < n ; i++)
	{
		string temp = s[i];
		int ww = 0, ii = 0, nn = 0;

		for (auto j : temp)
		{
			if (j == 'w')
				ww++;
			if (j == 'i')
				ii++;
			if (j == 'n')
				nn++;
		}

		if (ww > n)
		{
			if (ii < n)
				boro[ {fw, fi}].push_back(i);
			if (nn < n)
				boro[ {fw, fn}].push_back(i);
		}

		if (ii > n)
		{
			if (ww < n)
				boro[ {fi, fw}].push_back(i);
			if (nn < n)
				boro[ {fi, fn}].push_back(i);
		}

		if (nn > n)
		{
			if (ii < n)
				boro[ {fw, fi}].push_back(i);
			if (nn < n)
				boro[ {fw, fn}].push_back(i);
		}
	}

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