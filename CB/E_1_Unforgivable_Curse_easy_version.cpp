/*
* @Author: Zakaria
* @Date:   2023-03-02 22:08:53
* @Last Modified time: 2023-03-02 22:22:07
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
const int MAX = 2e5 + 6;


int Parent[MAX], Rank[MAX];

void Init(int n)
{
	for (int i = 1 ; i <= n ; i++)
		Rank[i] = 1, Parent[i] = i;
}

int Find_Parent(int v)
{
	if (v == Parent[v])
		return v;

	return Parent[v] = Find_Parent(Parent[v]);
}

void Union(int a, int b)
{
	a = Find_Parent(a);
	b = Find_Parent(b);

	if (a != b)
	{

		if (Rank[a] > Rank[b])
			swap (a, b);

		Parent[a] = b;
		Rank[b] += Rank[a];
	}
}

void Solve()
{


	int n, k;
	cin >> n >> k;


	string s, t;
	cin >> s >> t;

	s = '*' + s;
	t = '*' + t;

	Init(n);

	for (int i = 1 ; i <= n ; i++)
	{
		if (i + k <= n)
			Union(i, i + k);
		if (i + k + 1 <= n)
			Union(1, i + k + 1);
	}

	// for(int i=1 ; i<=n ; i++)
	// 	cout<<Find_Parent(i)<<" ";
	// cout<<endl;

	map<int, vector<int> > m;

	for (int i = 1 ; i <= n ; i++)
		m[Find_Parent(i)].push_back(i);


	for (int i = 1 ; i <= n ; i++)
	{
		vector<int>temp = m[i];

		map<char, int>freq;
		for (auto pos : temp)
			freq[s[pos]]++;

		// for(char i='a' ; i<='z' ; i++)
		// {
		// 	 if(freq[i])
		// 	 	cout<<i<<" "<<freq[i]<<endl;
		// }
		// cout<<endl;

		for (auto i : temp)
		{
			if (freq[t[i]])
				freq[t[i]]--;
			else
			{
				cout << "NO" << endl;
				return ;
			}
		}
	}

	cout << "YES" << endl;




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