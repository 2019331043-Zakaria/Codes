/*
* @Author: Zakaria
* @Date:   2023-01-20 00:27:50
* @Last Modified time: 2023-01-20 11:45:42
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

	int n, m;
	cin >> n >> m;

	ll a[n + 1][m + 1];
	ll Target[n + 1][m + 1];
	int cnt = 0;
	

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
			cin >> a[i][j], Target[i][j] = ++cnt;
	}

	int ans = 0;


	for(int j=1 ; j<=m ; j++)
	{
		map<int, vector<int> > pos;

		for(int i=1 ; i<=n ; i++)
		pos[a[i][j]].push_back(i);
		
		map<int, int>rotation;


		for(int i=1 ; i<=n ; i++)
		{
			int val = Target[i][j];
			
			for(auto k : pos[val])
			{
				rotation[(k - i + n)%n]++;
			}
		}

		int temp = 1e9;

		for(int i=0 ; i<n ; i++)
		{
			temp = min(temp, n - rotation[i] + i);
		}
		ans+=temp;

	}

	cout<<ans<<endl;


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	// cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}