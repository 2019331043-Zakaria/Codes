/*
* @Author: Zakaria
* @Date:   2023-03-29 00:23:30
* @Last Modified time: 2023-03-29 00:52:30
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

set<ll>st;
set<ll>all;

void Solve()
{

	ll n;
	cin >> n;

	int cnt = 0;

	for (auto i : all)
	{
		if (i >= n)
		{
			cout << i << endl;
			return ;
		}
	}


}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll pans = 1;

	for (int i = 0 ; i <= 38 ; i++)
	{
		st.insert(pans);
		pans *= 3;
	}

	cout << st.size() << endl;
	for (auto i : st)
	 all.insert(i);

	for (auto i : st)
	{
		for (auto j : st)
		{
			if(i!=j)
				all.insert(i+j);
		}
	}

	st = all;
	cout<<st.size()<<endl;
	all.clear();

	// for (auto i : st)
	// {
	// 	for (auto j : st)
	// 	{
	// 		for (auto k : st)
	// 		{
	// 			if (i != j && j != k && i!=k)
	// 				all.insert(i + j + k);

	// 			if (j != k)
	// 				all.insert(j + k);
	// 			if (i != k)
	// 				all.insert(i + k);
	// 			if (i != j)
	// 				all.insert(i + j);
	// 		}
	// 	}
	// }

	cout<<all.size()<<endl;


	int tt = 1;

	cin >> tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}