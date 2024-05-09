#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  endl        '\n'
typedef long long ll;
using namespace std;

const int mod = 1e9 + 7;
const int N = 2e5 + 6;

string s;

struct ehhe {

    int zero = 0, one = 0;
};

struct SegmentTree {
    vector<ehhe> tree;
    vector<int> lazy;

    SegmentTree()
    {
        tree.resize(4 * N);
        lazy.resize(4 * N);
        fill(lazy.begin(), lazy.end(), 0);
    }

    void push(int node, int b, int e)
    {
        if (lazy[node] == 0)
            return ;

        swap(tree[node].one, tree[node].zero);
        if (b != e)
        {
            lazy[2 * node] ^= 1;
            lazy[2 * node + 1] ^= 1;
        }

        lazy[node] = 0;
    }

    ehhe merge(ehhe p, ehhe q)
    {
        ehhe c;
        c.one = p.one + q.one;
        c.zero = p.zero + q.zero;

        return c;
    }


    void build(int node, int b, int e)
    {
        if (b == e)
        {
            tree[node].zero = (s[b - 1] == '0');
            tree[node].one = (s[b - 1] == '1');
            lazy[node] = 0;
            return;
        }

        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int b, int e, int l, int r)
    {

        push(node, b, e);

        if (l > e || r < b)
            return;

        if (l <= b && r >= e)
        {
            lazy[node] ^= 1;
            push(node, b, e);
            return;
        }

        int mid = (b + e) >> 1;
        update(2 * node, b, mid, l, r);
        update(2 * node + 1, mid + 1, e, l, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int b, int e, int l, int r)
    {

        push(node, b, e);

        if (l > e || r < b)
            return 0;

        if (l <= b && r >= e)
        {
            return tree[node].one;
        }

        int mid = (b + e) >> 1;
        return query(2 * node, b, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }
};

void Solve()
{

    SegmentTree st;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;

    st.build(1, 1, n);

    while (m--)
    {
        char c;
        cin >> c;

        if (c == 'I')
        {
            int l, r;
            cin >> l >> r;
            st.update(1, 1, n, l, r);
        }
        else
        {
            int x;
            cin >> x;
            cout << st.query(1, 1, n, x, x) << endl;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1, testcase = 1;

    cin >> tt;

    while (tt--)
    {

        cout << "Case " << testcase++ << ":\n";

        Solve();
    }

    return 0;

}



