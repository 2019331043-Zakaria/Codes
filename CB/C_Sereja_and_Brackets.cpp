/*
* @Author: Zakaria
* @Date:   2023-02-01 01:36:22
* @Last Modified time: 2023-02-01 02:25:59
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
const int N = 1e6 + 6;


struct node
{
	ll open = 0;
	ll close = 0;
	ll regular = 0;
};


node tree[4 * N];
string s;



void Update(int n, int l, int r)
{

	if (l == r)
	{
		if (s[l] == '(')
			tree[n].open = 1;
		else
			tree[n].close = 1;

		return ;
	}

	int left = 2 * n;
	int right = 2 * n + 1;


	int mid = (l + r) >> 1;

	Update(left, l, mid);

	Update(right, mid + 1, r);

	//Merge
	node temp ;
	temp.regular = tree[left].regular + tree[right].regular + 2 * min(tree[left].open, tree[right].close);

	temp.open = tree[left].open + tree[right].open - min(tree[left].open, tree[right].close);

	temp.close = tree[left].close + tree[right].close - min(tree[left].open, tree[right].close);

	tree[n] = temp;


}

node Query(int n, int b, int e, int l, int r)
{

	if (l > e || r < b)
	{
		node temp;
		return temp;
	}

	if (b >= l && e <= r)
		return tree[n];

	int left = 2 * n;
	int right = 2 * n + 1;


	int mid = (b + e) >> 1;

	node leftnode = Query(left, b, mid, l, r);
	node rightnode = Query(right, mid + 1, e, l, r);

	node temp;
	temp.regular = leftnode.regular + rightnode.regular + 2 * min(leftnode.open, rightnode.close);
	temp.open = leftnode.open + rightnode.open - min(leftnode.open, rightnode.close);
	temp.close = leftnode.close + rightnode.close - min(leftnode.open, rightnode.close);

	return temp;

}

void Solve()
{


	cin >> s;

	int n = s.size();
	s = '*' + s;
	Update(1, 1, n);

	int q;
	cin >> q;

	while (q--)
	{
		int l, r;
		cin >> l >> r;

		cout << Query(1, 1, n, l, r).regular << endl;
	}

}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;

	//  cin>>tt;

	while (tt--)
	{

		Solve();
	}

	return 0;

}