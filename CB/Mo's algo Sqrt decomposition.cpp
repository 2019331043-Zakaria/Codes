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
const int N = 5e5 + 6;
const int BLOCK_SIZE = 500;

struct Query {
 
    int l, r, idx,  lc, type;
 
    bool operator<(const Query &y) const {
        // Current query x is being compared with other query y
        int x_block = l / BLOCK_SIZE;
        int y_block = y.l / BLOCK_SIZE;
 
        // If x and y both lie in the same block, sort in non decreasing order of endpoint
        if (x_block == y_block)
            return r < y.r;
 
        // x and y lie in different blocks
        return x_block < y_block;
    }
};


ll nc3(ll x)
{
    if (x < 3)
        return 0;
    return (x * (x - 1) * (x - 2)) / 6;
}

int a[N];
ll last[N];
ll freq[N];
ll res;

void Add(int i)
{

    int x = a[i];

    res -= last[x];

    freq[x]++;

    last[x] = nc3(freq[x]);
    res += last[x];
}


void Remove(int i)
{

    int x = a[i];

    res -= last[x];

    freq[x]--;

    last[x] = nc3(freq[x]);
    res += last[x];
}

void Solve()
{

    int n, q;
    cin >> n >> q;

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }

    vector<Query>queries;
    ll ans[q + 1];

    for (int i = 1 ; i <= q ; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    sort(queries.begin(), queries.end());

    int Left = 1, Right = 0;
    for (auto i : queries)
    {
        int l = i.l;
        int r = i.r;
        int id = i.idx;

        while (Right < r)
            Add(++Right);

        while (Left > l)
            Add(--Left);

        while (Left < l)
            Remove(Left++);

        while (Right > r)
            Remove(Right--);

        ans[i.idx] = res;
    }


    for (int i = 1 ; i <= q ; i++)
        cout << ans[i] << endl;


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

//https://atcoder.jp/contests/abc293/tasks/abc293_g