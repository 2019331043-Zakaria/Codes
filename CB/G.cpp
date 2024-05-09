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

mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> gen(0, LLONG_MAX);

const int mod = 1e9 + 7;
const int N = 3e5 + 9, LG = 18;

vector<int> node[N];
int par[N][LG + 1], dep[N], sz[N];
int timer;

int intime[N];

void dfs(int u, int p = 0)
{
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    intime[u] = ++timer;

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

vector<int>virtualnode[N];

bool foo(vector<int>v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    cout<<"after "<<endl;

    vector<pair<int, int> > ntime;
    for (auto i : v)
        ntime.push_back({intime[i], i});

    sort(ntime.rbegin(), ntime.rend());

    int cnt = 0;

    stack<int>current;
    current.push(ntime[0].s);

    for (int i = 1 ; i < ntime.size(); i++)
    {

        if (lca(current.top(), ntime[i].s) == current.top())
        {
            cout<<current.top()<<" "<<ntime[i].s<<endl;
            virtualnode[current.top()].push_back(ntime[i].s);
            virtualnode[ntime[i].s].push_back(current.top());
            current.push(ntime[i].s);
        }
        else
        {
            int pp = -1;
            while(current.size())
            {
                pp = current.top();
                current.pop();

                if(current.size())
                    pp = current.top();
                else
                    break;

                int lc = lca(ntime[i].s, pp);

                if(pp==lc)
                {
                    cout<<pp<<" "<<ntime[i].s<<endl;
                    virtualnode[pp].push_back(ntime[i].s);
                    virtualnode[ntime[i].s].push_back(pp);
                    pp = -1;
                    current.push(ntime[i].s);
                    break;
                }
            }

            if(pp!=-1)
            {
                int lc = lca(ntime[i].s, pp);

                cout<<lc<<" b "<<ntime[i].s<<endl;
                cout<<pp<<" "<<lc<<endl;

                virtualnode[lc].push_back(ntime[i].s);
                virtualnode[ntime[i].s].push_back(lc);
                virtualnode[pp].push_back(lc);
                virtualnode[lc].push_back(pp);
                current.push(lc);
                current.push(ntime[i].s);
            }

        }

    }




    return cnt <= 2;
}

void Solve()
{


    int n;
    cin >> n;

    for (int i = 1 ; i <= n ; i++)
    {
        node[i].clear();
        dep[i] = 0, sz[i] = 0, intime[i] = 0, timer = 0;
    }

    for (int i = 1 ; i < n ; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1);

    int q;
    cin >> q;

    cout << q << endl;
    for (int i = 1 ; i <= q ; i++)
    {
        int x;
        cin >> x;
        vector<int>v;
        for (int j = 1 ; j <= x ; j++)
        {
            int u;
            cin >> u;
            v.push_back(u);
        }

        if (foo(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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