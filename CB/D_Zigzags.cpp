/*
* @Author: Zakaria
* @Date:   2023-04-08 02:14:13
* @Last Modified time: 2023-04-08 15:12:20
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

int leftfreq[N], rightfreq[N];

void Solve()
{

	int n;
	cin >> n;

	int a[n];
	for (int i = 0 ; i < n ; i++)
		cin >> a[i], a[i]--, leftfreq[i] = 0;


	ll ans = 0;

	for(int i = 0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
			rightfreq[j] = 0;

		for(int j=n-1 ; j>i ; j--)
		{
			ans+=leftfreq[a[j]]*rightfreq[a[i]];
			rightfreq[a[j]]++;
		}

		leftfreq[a[i]]++;
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