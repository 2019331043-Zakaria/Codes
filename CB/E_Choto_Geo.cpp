/*
* @Author: Zakaria
* @Date:   2023-03-18 17:32:56
* @Last Modified time: 2023-03-18 23:34:00
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
const int N = 5e5 + 6;

vector<int>d[N];

void Solve()
{

	int a, b, m1, m2;
	cin >> a >> b >> m1 >> m2;

	if (m1 == 0 && m2 == 0)
	{
		cout << 1 << endl;
		return ;
	}

	if (m1 > a || m2 > b)
	{
		cout << -1 << endl;
		return ;
	}

	if (m1 == a && m2 == b)
	{
		cout << max(a, b) + 1 << endl;
		return ;
	}


	int tempa = a - m1;

	int tempb = b - m2;

	int ehhe = GCD(tempa, tempb);





	vector<int>temp;
	temp = d[ehhe];

	int low = 0, high = temp.size() - 1, mid;
	int ans = -1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int pans = temp[mid];

		if (a % pans == m1 && b % pans == m2)
		{
			ans = pans;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << ans << endl;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);



	for (int i = 1 ; i < N ; i++)
	{
		for (int j = i ; j < N ; j += i)
			d[j].push_back(i);
	}



	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}