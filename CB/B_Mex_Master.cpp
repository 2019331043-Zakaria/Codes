/*
* @Author: Zakaria
* @Date:   2023-03-24 14:49:36
* @Last Modified time: 2023-03-24 15:07:10
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

	int a[n];

	int zero = 0;
	int one = 0;
	int mx = 0;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
		zero += (a[i] == 0);
		one += (a[i] == 1);
		mx = max(mx, a[i]);
	}

	if (zero == n)
	{
		cout << 1 << endl;
		return ;
	}

	if(zero<=(n+1)/2)
	{
		cout<<0<<endl;
	}
	else if(mx!=1)
	{
		cout<<1<<endl;
	}
	else
		cout<<2<<endl;


	





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