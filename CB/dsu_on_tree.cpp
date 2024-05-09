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

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

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
const int N = 5e5 + 6;

int n, m;

vector<int>node[N];
int cnt[N][30];
bool big[N];
int sz[N];
int depth[N];
string s;
vector<pair<int, int> > queries[N];
int ans[N];

void subsz(int v, int p)
{
    sz[v] = 1;
    depth[v] = depth[p] + 1;

    for (auto i : node[v])
    {
        if (i != p)
        {
            subsz(i, v);
            sz[v] += sz[i];
        }
    }
}

void ProcessQueries(int v)
{
    for (auto i : queries[v])
    {
        int h = i.f;
        int idx = i.s;
        int ok = 0;

        for (int i = 0 ; i <= 26 ; i++)
        {
            ok += (cnt[h][i] % 2);
        }

        ans[idx] = (ok > 1);
    }
}

void add(int v, int p, int x)
{
    cnt[depth[v]][s[v] - 'a'] += x;
    for (auto u : node[v])
    {
        if (u != p && !big[u])
        {
            add(u, v, x);
        }
    }
}
void dfs(int v, int p, bool keep)
{
    int mx = -1, bigChild = -1;

    for (auto u : node[v])
        if (u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;

    for (auto u : node[v])
        if (u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt

    if (bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt

    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    ProcessQueries(v);

    if (bigChild != -1)
        big[bigChild] = 0;
    if (keep == 0)
        add(v, p, -1);
}

void Solve()
{

    int n, q ;
    cin >> n >> q;

    for (int i = 2 ; i <= n ; i++)
    {
        int x;
        cin >> x;
        node[x].push_back(i);
        node[i].push_back(x);
    }

    cin >> s;

    for (int i = 1 ; i <= q ; i++)
    {
        int u, h;
        cin >> u >> h;
        queries[u].push_back({h, i});
    }
    s = "*" + s;

    subsz(1, 0);

    // for (int i = 1 ; i <= n ; i++)
    //     cout << i << " " << sz[i] << endl;
    dfs(1, 0, 0);

    for (int i = 1 ; i <= q ; i++)
        if (!ans[i])
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";

    cout << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    // cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}


//https://codeforces.com/contest/570/problem/D