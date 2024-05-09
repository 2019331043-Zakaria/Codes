/*
* @Author: Zakaria
* @Date:   2023-03-19 22:28:36
* @Last Modified time: 2023-03-25 13:37:51
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


bool vis[25005][25005];

int n, m, inx, iny, finx, finy;

int dx , dy;



void Solve()
{


	cin >> n >> m >> inx >> iny >> finx >> finy;

	string s;
	cin >> s;

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
			vis[i][j] = 0;
	}

	int ans = 0;

	if (s == "DL")
		dx = 1, dy = -1;
	if (s == "DR")
		dx = 1, dy = 1;
	if (s == "UL")
		dx = -1, dy = -1;
	if (s == "UR")
		dx = -1, dy = 1;

	
	int cnt = 4 * n * m;

	while (cnt--)
	{


		inx += dx;
		iny += dy;

		if (inx == finx && iny == finy)
		{
			cout << ans << endl;
			return ;
		}

		if (inx == 0 && iny == 0)
			break;
		if (inx == 0 && iny == m + 1)
			break;
		if (inx == n + 1 && iny == 0)
			break;
		if (inx == n + 1 && inx == m + 1)
			break;

		if (inx == 0)
		{

			//cout<<"here1"<<endl;

			if (dx == -1 && dy == -1)
			{
				dx = 1, dy = -1;
			}
			else if (dx == -1 && dy == 1)
			{
				dx = 1;
				dy = 1;
			}
			ans++;
			inx = 2;
		}

		if (inx == n + 1)
		{

			//cout<<"here2"<<endl;

			if (dx == 1 && dy == 1)
			{
				dx = -1, dy = 1;
			}
			else if (dx == 1 && dy == -1)
			{

				dx = -1;
				dy = -1;
			}
			ans++;
			inx = n - 1;
		}


		if (iny == 0)
		{

			//cout<<"here3"<<endl;

			if (dx == 1 && dy == -1)
			{
				dx = 1, dy = 1;
			}
			else if (dx == -1 && dy == -1)
			{
				dx = -1;
				dy = 1;
			}
			ans++;
			iny = 2;

		}

		if (iny == m + 1)
		{

			//cout<<"here4"<<endl;

			if (dx == 1 && dy == 1)
			{
				dx = 1, dy = -1;
			}
			else if (dx == 1 && dy == -1)
			{
				dx = 1;
				dy = 1;
			}
			ans++;
			iny = m - 2;
		}

		cout << inx << " " << iny << endl;

		if (inx == finx && iny == finy)
		{
			cout << ans << endl;
			return ;
		}

		if ((inx == 1 && iny == 1) or (inx == 1 && iny == n) or (inx == n && iny == 1) or (inx == n && iny == m))
		{
			break;
		}


	}

	cout << -1 << endl;



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