#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 6;

void Solve()
{

	int x, n, m;
	cin >> x >> n >> m;

	int ans = 0;

	for (int i = 1 ; i <= min(n, m) ; i++)
	{
		if (i + i - 1 <= x)
			ans = i;
	}

	
	char a[n][m];

	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < m ; j++)
			a[i][j] = '.';
	}

	for(int i=0 ; i<ans ; i++)
	{
		if(a[0][i]=='.' && x)
		{
			a[0][i] = '#';
			x--;
		}
	}

	for(int i=0 ; i<ans ; i++)
	{
		if(a[i][0]=='.' && x)
		{
			a[i][0] = '#';
			x--;
		}
	}

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			if(a[i][j]=='.' && x)
			{
				a[i][j] = '#';
				x--;
			}
		}
	}

	cout<<ans<<endl;

	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);


	// freopen("class.in", "r", stdin);
	// freopen("class.out", "w", stdout);

	int tt = 1, testcae = 1;

	//cin>>tt;

	while (tt--)
	{
		Solve();
	}

	return 0;

}


As you have to find the maximum row and column fullness, it is optimal to seat the maximum number of students in a single row and a single column.
The optimal way is to seat the first student in the 1st row and 1st column as it will contribute to both row fullness and column fullness. 
Now, you can find the maximum class fullness, p (0<= p <= min(r, c) such that 2*p - 1 is less than or equal to n. 
Then you have to fill the first p number of cells from the first row as well as from the first column.
Then the remaining number of students which is n - (2*p - 1) can be seated in any arrangement. 
