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

ll a[N], b[N];
vector<int>node[N];
ll ans[30];
ll bit[N];
ll dp[N][2];

void dfs(int p, int par, int k) // Find contribution for each bit -> number of path having xor 1
{

    dp[p][b[p] % 2] = 1;

    for (auto i : node[p])
    {
        if (i == par) continue;

        dfs(i, p, k);

        ans[k] += ((1LL * dp[p][0] * dp[i][1]) + (1LL * dp[p][1] * dp[i][0])); // Calculate;

        if (b[p])
            swap(dp[i][0], dp[i][1]);

        dp[p][0] += dp[i][0];
        dp[p][1] += dp[i][1];
    }
}


void Solve()
{

    int n;
    cin >> n;

    ll total = 0;

    for (int i = 1 ; i <= n ; i++)
        cin >> a[i], total += a[i];

    for (int i = 1 ; i < n ; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int k = 0 ; k < 30 ; k++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            b[i] = (a[i] & (1 << k)) ? 1 : 0;
        }

        for (int i = 1 ; i <= n ; i++)
            dp[i][0] = dp[i][1] = 0;

        dfs(1, 0, k);
        //db(k, ans[k]);
        total += (1LL << k) * ans[k];
    }

    cout << total << endl;


}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    //    cin>>tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}