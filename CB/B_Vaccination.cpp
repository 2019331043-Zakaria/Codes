/*
* @Author: Zakaria
* @Date:   2023-03-12 20:47:33
* @Last Modified time: 2023-03-12 21:51:18
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

ll n, k, d, w;
ll a[N];


void Solve()
{


	cin >> n >> k >> d >> w;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];


	int ans = 1;
	ll open = a[1] + w;
	int cnt = 0;

	for(int i=1 ; i<=n ; i++)
	{
		if(cnt==k)
		{
			ans++;
			open = a[i] + w;
			cnt = 0;
		}

		if(a[i]<=open || a[i] - open<=d)
		{
			cnt++;
		}
		else
		{
			ans++;
			cnt = 1;
			open = a[i] + w;

		}
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