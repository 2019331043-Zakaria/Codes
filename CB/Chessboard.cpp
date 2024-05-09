
//64b54319eafa0636defd2e1a
#include <bits/stdc++.h>
using namespace std;

void Solve()
{

	int p;

	int testcase = 0;

	while (cin >> p)
	{
		cout << "Case #" << ++testcase << ": ";
		if (p == 0)
		{
			cout << 0 << endl;
		}
		else if (p <= 78)
		{
			cout << 1 << endl;
		}
		else if (p <= 95)
		{
			cout << 2 << endl;
		}
		else if (p <= 99)
		{
			cout << 3 << endl;
		}
		else
			cout << 4 << endl;
	}

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	// freopen("chessmaster.in", "r", stdin);
	// freopen("chessmaster.out", "w", stdout);

	int tt = 1;
	//cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}


// You have been given a regular chessboard and a laser whose beam diameter is half of the length of the chessboard's side.
// You have to find the minimum number of laser shoots required to destroy p% of the chessboard's surface.
// The laser shoot only in the direction orthogonal to the chessboard.

// summary:
// You have been given a regular chessboard and a laser whose beam diameter is equal to the length of the chessboard's side.
// You have to find the minimum number of laser shoots required to destroy p% of the chessboard's surface.
// The laser shoot only in the direction orthogonal to the chessboard.

// ediitorial
// As the given chessboard is regular so its dimension is 8*8, also the given that the laser beam diameter is eq