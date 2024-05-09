/*
* @Author: Zakaria
* @Date:   2023-03-26 02:30:51
* @Last Modified time: 2023-03-26 02:44:39
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

	map<pair<ll, ll> , int>m;

	int left = 0, right = 0;
	int up = 0, down = 0;
	int p = 0;

	for (int i = 1 ; i <= n ; i++)
	{
		int x, y;
		cin >> x >> y;

		if (x == 0)
		{
			if (y < 0)
				down = 1;
			else if (y > 0)
				up = 1;
			else
				p = 1;
		}
		else
		{

			if (x < 0 && y==0)
				left = 1;
			else if (x > 0 && y==0)
				right = 1;
			else
			{

				ll G = GCD(abs(x), abs(y));
				x/=G;
				y/=G;
				m[{x, y}]++;
			}
		}
	}

	if (p == 1)
	{
		cout << 1 << endl;
		return ;
	}



	cout << m.size() + left + right + up + down<< endl;

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