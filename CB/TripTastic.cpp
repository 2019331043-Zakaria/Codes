/*
* @Author: Zakaria
* @Date:   2023-04-12 22:08:35
* @Last Modified time: 2023-04-12 22:44:47
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

	ll n, m, k;
	cin >> n >> m >> k;

	ll a[n + 1][m + 1];
	for(int i=0 ; i<=n ; i++)
	{
		for(int j=0 ; j<=m ; j++)
			a[i][j] = 0;
	}

	ll sum = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
		}
	}

	if (sum < k+1)
	{
		cout << -1 << endl;
		return ;
	}

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			 if(a[i][j]>k)
			 {
			 	cout<<0<<endl;
			 	return ;
			 }
		}
	}

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1; j <= m ; j++)
			a[i][j] += a[i][j - 1];
	}


	for (int j = 1 ; j <= m ; j++)
	{
		for (int i = 1 ; i <= n ; i++)
		{
			//cout<<i<<" "<<j<<endl;
			a[i][j] += a[i - 1][j];
		}
	}

	// for (int i = 1 ; i <= n ; i++)
	// {
	// 	for (int j = 1 ; j <= m ; j++)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }

	// cout<<endl;

    int ans = 1e9;
    ll res = 1e9;

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			int low = 1, high = 1e9;
			
			while (low <= high)
			{
				ll mid = (low + high) / 2;

                // cout<<i<<" "<<j<<endl;
                // cout<<"after "<<mid<<endl;


				int l1 = max(1LL , i - mid );
				int r1 = max(1LL , j - mid);

				int l2 = i;
				int r2 = j;


				// cout<<l1<<" "<<r1<<endl;
				// cout<<l2<<" "<<r2<<endl;


				ll tot = a[l2][r2] - a[l1-1][r2] - a[l2][r1-1] + a[l1-1][r1-1];

				// cout<<tot<<endl;
				// cout<<endl;


				if(tot>=k+1)
				{
					high = mid - 1;
					ans = min(ans, max(abs(l1- l2), abs(r1-r2)));
					
				}
				else
					low = mid + 1;
			}
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