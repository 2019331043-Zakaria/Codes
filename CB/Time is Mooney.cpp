/*
* @Author: Zakaria
* @Date:   2023-07-09 22:23:02
* @Last Modified time: 2023-07-11 00:03:47
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

#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
	cerr << *it << "=" << a << " ! ";
	err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.f << ", " << p.s << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "["; for (auto it = v.begin (); it != v.end (); ++it) { if (it != v.begin ())out << ", "; out << *it; } return out << "]"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class T> ostream& operator << (ostream& out, multiset<T>& s) { out << "{"; for (auto it = s.begin (); it != s.end (); ++it) { if (it != s.begin ())out << ", "; out << *it; } return out << "}"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{"; for (auto it = m.begin (); it != m.end (); ++it) { if (it != m.begin ())out << ", "; out << *it; } return out << "}"; }



const int mod = 1e9 + 7;
const int N = 2e5 + 6;

void Solve()
{

	int n, m, k;
	cin >> n >> m >> k;
	int a[n + 1];
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];

	vector<pair<int, int> > v;

	for(int i=1 ; i<=m ; i++)
	{
		int u, p;
		cin>>u>>p;
		v.push_back({u, p});
	}

	int dp[1002][n+1];
	memset(dp, -1, sizeof(dp));

	dp[0][1] = 0;
	int ans = 0;
	for(int i=1 ; i<=1000 ; i++)
	{
		for(auto j:v)
		{
			int u = j.f;
			int v = j.s;
			if(dp[i-1][u]+1)
				dp[i][v] = max(dp[i][v], dp[i-1][u] + a[v]);
		}
		ans = max(ans, dp[i][1] - k*i*i);
	}

	cout<<ans<<endl;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	int tt = 1, testcae = 1;

	//    cin>>tt;

	while (tt--)
	{

		//cout<<"Case "<<testcae++<<": ";

		Solve();
	}

	return 0;

}