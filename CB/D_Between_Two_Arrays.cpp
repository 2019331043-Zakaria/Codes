#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define fastio            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define aa                auto
#define ll                long long
#define ull               unsigned long long
#define ld                long double
#define fr                first
#define sc                second
#define pll               pair<ll,ll>
#define tll               pair<pll,ll>
#define vll               vector<ll>
#define bp(x)             __builtin_popcountll(x)
#define msb(x)            (63-__builtin_clzll(x))
#define all(a)            a.begin(),a.end()
#define arr(a)            a.rbegin(),a.rend()
#define cb(a,i)           (a>>i&1)
#define mp(a,b)           make_pair(a,b)
#define mt(a,b,c)         mp(mp(a,b),c)
#define lb(a)             lower_bound(a)
#define ub(a)             upper_bound(a)
#define pb(a)             push_back(a)
#define ve                vector
#define lc                (u << 1 | 1)
#define rc                (u + 1 << 1)


#define db(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << "\n\n";}
void err (istream_iterator<string> it) {}
template<typename T, typename... Args>
void err (istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=" << a << " ! ";
    err (++it, args...);
}

template<class L, class R> ostream& operator << (ostream& out, pair<L, R>& p) { return out << "(" << p.fr << ", " << p.sc << ")"; }
template<class T> ostream& operator << (ostream& out, vector<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]"; }
template<class T> ostream& operator << (ostream& out, deque<T>& v) { out << "[";for (auto it = v.begin ();it != v.end ();++it) { if (it != v.begin ())out << ", ";out << *it; }return out << "]"; }
template<class T> ostream& operator << (ostream& out, set<T>& s) { out << "{";for (auto it = s.begin ();it != s.end ();++it) { if (it != s.begin ())out << ", ";out << *it; }return out << "}"; }
template<class T> ostream& operator << (ostream& out, multiset<T>& s) { out << "{";for (auto it = s.begin ();it != s.end ();++it) { if (it != s.begin ())out << ", ";out << *it; }return out << "}"; }
template<class L, class R> ostream& operator << (ostream& out, map<L, R>& m) { out << "{";for (auto it = m.begin ();it != m.end ();++it) { if (it != m.begin ())out << ", ";out << *it; }return out << "}"; }

const ll N = 3007, inf = 2e18;
const ld eps = 1e-8;
// const ll M = 1e9 + 7;
const ll M = 998244353;


/******************** Aladeen Matha Faka ***********************/


ll a[N], b[N];
string s;
ll n, m;
ll f[2][N], c[2][N];

ll add (ll a, ll b) { return (a + b) % M; }
ll sub (ll a, ll b) { return add (a, M - b); }

void solve (ll tt) {
    ll i, j, k, x, y, u, v;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    for (j = 0, i = n - 1; j < N; j++) {
        f[i & 1][j] = j <= b[i] ? b[i] - max (a[i], j) + 1 : 0;
        c[i & 1][j] = add ( j ? c[i & 1][j - 1] : 0, f[i & 1][j]);
        // if (j <= b[i]) db (i, j, f[i&1][j]);
    }
    for (i = n - 2; i >= 0; i--) {
        for (j = 0; j < N; j++) {
            f[i & 1][j] = j <= b[i] ? sub (c[(i + 1) & 1][b[i]], max (a[i], j) ? c[(i + 1) & 1][max (a[i], j) - 1] : 0) : 0;
            // if (j <= b[i]) db (i, j, f[i&1][j]);
            c[i & 1][j] = add ( j ? c[i & 1][j - 1] : 0, f[i & 1][j]);
        }
    }
    cout << f[0][a[0]] << "\n";
}

main () {
    fastio;
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) solve (i);
}