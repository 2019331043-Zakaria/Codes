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


struct Segmentree
{

#define lc (node << 1)
#define rc ((node << 1) | 1)

    vector<ll>tree;
    vector<ll>lazy;

    Segmentree()
    {
        tree.resize(4 * N);
        lazy.resize(4 * N);
        fill(tree.begin(), tree.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
    }

    void push(ll node, ll b, ll e)
    {
        if (lazy[node] == 0)
            return ;

        tree[node] += lazy[node];

        if (b != e)
        {
            lazy[lc] += lazy[node];
            lazy[rc] += lazy[node];
        }

        lazy[node] = 0;
    }

    void build(ll node, ll b, ll e) {

        if (b == e) {
            tree[node] = 0;
            lazy[node] = 0;
            return;
        }



        ll mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);

        tree[node] = tree[lc] + tree[rc];

    }
    void update(ll node, ll b, ll e, ll l, ll r, ll x)
    {

        push(node, b, e);

        if (l > e || r < b)
            return ;

        if (l <= b && r >= e)
        {
            lazy[node] += x;
            push(node, b, e);
            return ;
        }

        ll mid = (b + e) >> 1;
        update(lc, b, mid, l, r, x);
        update(rc, mid + 1, e, l, r, x);

        tree[node] = tree[lc] + tree[rc];
    }

    ll query(ll node, ll b, ll e, ll idx)
    {

        push(node, b, e);

        if (b > idx || e < idx)
            return 0;

        if (b == e && b == idx)
        {
            return tree[node];
        }

        ll mid = (b + e) >> 1;
        return query(lc, b, mid, idx) + query(rc, mid + 1, e, idx);
    }

};


void Solve()
{

    Segmentree st;


    int n, q;
    cin >> n >> q;

    //st.build(1, 1, n);

    //st.update(1, 1, n, 1, 1, 1);

    while (q--)
    {
        int type ;
        cin >> type;

        if (type == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l++;
            st.update(1, 1, n, l, r, x);
        }
        else
        {
            ll idx;
            cin >> idx;
            cout << st.query(1, 1, n, idx + 1) << endl;
        }

    }

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int tt = 1, testcae = 1;

    //cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}