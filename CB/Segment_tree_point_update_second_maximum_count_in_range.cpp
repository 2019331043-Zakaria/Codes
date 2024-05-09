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
const int N = 5e5 + 6;

struct info
{
    int fmax = 0;
    int fmaxcount = 1;
    int smax = 0;
    int smaxcount = 0;
};

info bal;

int a[N];
struct SegmentTree {
    vector<info> tree;

    SegmentTree() {
        tree.resize(4 * N);
    }


    info merge(info p, info q)
    {

        info c;
        vector<pair<int, int> > v;
        v.push_back({p.fmax, p.fmaxcount});
        v.push_back({p.smax, p.smaxcount});
        v.push_back({q.fmax, q.fmaxcount});
        v.push_back({q.smax, q.smaxcount});


        sort(v.begin(), v.end());

        // db(v)

        int mx = v.back().f;
        int secmxcnt = 0;
        int mxcnt = 0;
        for (auto i : v)
        {
            if (i.f == mx)
                mxcnt += i.s;
        }
        int sex = 0;
        for (auto i : v)
        {
            if (i.f != mx)
            {
                sex = max(sex, i.f);
            }
        }

        if (sex != 0)
        {
            for (auto i : v)
            {
                if (i.f == sex)
                    secmxcnt += i.s;
            }
        }

        c.fmax = mx;
        c.fmaxcount = mxcnt;
        c.smax = sex;
        c.smaxcount = secmxcnt;

        return c;
    }

    void build(ll node, ll b, ll e) {

        if (b == e)
        {

            tree[node].fmax = a[b];
            tree[node].smax = 0;
            tree[node].fmaxcount = 1;
            tree[node].smaxcount = 0;
            return;
        }

        ll mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = merge(tree[2 * node] , tree[2 * node + 1]);
    }

    void update(ll node, ll b, ll e, ll l, ll x) {

        if (l > e || l < b)
            return;

        if (b == e && b == l)
        {

            tree[node].fmax = x;
            tree[node].smax = -1;
            tree[node].fmaxcount = 1;
            tree[node].smaxcount = 0;
            return;
        }

        ll mid = (b + e) >> 1;
        update(2 * node, b, mid, l, x);
        update(2 * node + 1, mid + 1, e, l, x);
        tree[node] = merge(tree[2 * node] , tree[2 * node + 1]);
    }

    info query(ll node, ll b, ll e, ll l, ll r) {

       
        if (l > e || r < b)
            return bal;

        if (l <= b && r >= e)
        {
            return tree[node];
        }

        ll mid = (b + e) >> 1;
        return merge(query(2 * node, b, mid, l, r), query(2 * node + 1, mid + 1, e, l, r));
    }
};
SegmentTree st;




void Solve()
{

    int n, q;
    cin >> n >> q;

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }

    st.build(1, 1, n);


    // cout << st.query(1, 1, n, 2, 4).smaxcount << endl;

    while (q--)
    {
        int t , l, r;
        cin >> t >> l >> r;

        if (t == 2)
        {
            cout << st.query(1, 1, n, l, r).smaxcount << endl;
        }
        else
        {
            st.update(1, 1, n, l, r);
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

    // cin >> tt;

    while (tt--)
    {

        //cout<<"Case "<<testcae++<<": ";

        Solve();
    }

    return 0;

}