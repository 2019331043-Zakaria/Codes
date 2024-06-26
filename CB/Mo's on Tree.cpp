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




const int mod = 1e9 + 7, LG = 18;
const int N = 2e5 + 6;
const int BLOCK_SIZE = 450;

struct Query {

    int l, r, idx, c, lc, type;

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

int a[N];

vector<int>node[N];
int starttime[N], endtime[N];
int ft[N];
int par[N][LG + 1], dep[N], sz[N];
int timer = 1;

void dfs(int u, int p = 0)
{

    ft[timer] = u;
    starttime[u] = timer++;
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++)
    {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }

    for (auto v : node[u])
    {
        if (v == p) continue;

        dfs(v, u);
        sz[u] += sz[v];
    }

    ft[timer] = u;
    endtime[u] = timer++;
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);

    for (int k = LG; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v)
        return u;
    for (int k = LG; k >= 0; k--)
        if (par[u][k] != par[v][k])
            u = par[u][k], v = par[v][k];

    return par[u][0];
}

int freq[N];
int colour[N];
int res;

void operation(int id)
{
    int curnode = ft[id];
    int c = a[curnode];

    if (freq[curnode] == 0)
    {
        colour[c]++;
        if (colour[c] == 1)
            res++;
    }
    else
    {
        colour[c]--;
        if (colour[c] == 0)
            res--;
    }

    freq[curnode] ^= 1;
}


void Solve()
{

    int n, q;

    while (cin >> n >> q)
    {

        set<ll>st;
        map<ll , ll>m;

        for (int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];

            //cout << a[i] << " ";
        }

        //cout << endl;


        int tot = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            if (m[a[i]])
                a[i] = m[a[i]];
            else
            {
                m[a[i]] = ++tot;
                a[i] = m[a[i]];
            }
        }

        // for (int i = 1 ; i <= n ; i++)
        //     cout << a[i] << " ";
        // cout << endl;

        for (int i = 1 ; i < n ; i++)
        {
            int u, v;
            cin >> u >> v;
            node[u].push_back(v);
            node[v].push_back(u);
        }

        dfs(1);

        ll ans[q + 1];
        Query queries[q];

        for (int i = 0 ; i < q ; i++)
        {
            int u, v, c;
            cin >> u >> v;

            int lc = lca(u, v);

            if (dep[u] > dep[v])
                swap(u, v);

            //cout << u << " " << v << endl;

            if (lc == u || lc == v)
                queries[i] = {starttime[u], starttime[v], i + 1, 1, lc, -1};
            else
                queries[i] = {endtime[u], starttime[v], i + 1, 1, lc, 1};
        }

        sort(queries, queries + q);

        // for (auto i : queries)
        // {
        //     cout << i.l << " " << i.r << " " << i.type << " " << i.c << endl;
        // }


        int Left = 1, Right = 0;
        for (auto i : queries)
        {
            int l = i.l;
            int r = i.r;
            int id = i.idx;
            int c = i.c;
            int type = i.type;
            int lc = i.lc;

            while (Right < r)
                operation(++Right);

            while (Left > l)
                operation(--Left);

            while (Left < l)
                operation(Left++);

            while (Right > r)
                operation(Right--);

            if (type == 1)
            {
                operation(starttime[lc]);
            }

            ans[id] = res;

            if (type == 1)
                operation(starttime[lc]);
        }


        for (int i = 1 ; i <= q ; i++)
        {
            cout << ans[i] << endl;
        }
        //cout << endl;

        for (int i = 1 ; i <= n + n + 4 ; i++)
        {
            starttime[i] = endtime[i] = 0;
            timer = 1;
            freq[i] = 0;
            node[i].clear();
            colour[i] = 0;
            res = 0;
            ft[i] = 0;
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

//https://www.spoj.com/problems/COT2/