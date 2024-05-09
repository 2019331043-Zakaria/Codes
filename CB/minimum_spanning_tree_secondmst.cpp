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

const int N = 3e5 + 9, LG = 18;

vector<pair< int, int > > node[N];
int par[N][LG + 1], dep[N], sz[N];
int dis[N][LG + 1];

void dfs(int u, int p = 0, int w = 0)
{
        par[u][0] = p;
        dis[u][0] = w;
        dep[u] = dep[p] + 1;
        sz[u] = 1;
        for (int i = 1; i <= LG; i++)
        {
                par[u][i] = par[par[u][i - 1]][i - 1];

                dis[u][i] = max(dis[u][i - 1], dis[par[u][i - 1]][i - 1]);
        }

        for (auto v : node[u])
        {
                if (v.f == p) continue;

                dfs(v.f, u, v.s);
                sz[u] += sz[v.f];
        }
}

int maxedgepath(int u, int v)
{
        if (dep[u] < dep[v])
                swap(u, v);

        int mx = 0;

        for (int k = LG; k >= 0; k--)
        {
                if (dep[par[u][k]] >= dep[v])
                {
                        mx = max(mx, dis[u][k]);
                        u = par[u][k];
                }
        }

        if (u == v)
                return mx;

        for (int k = LG; k >= 0; k--)
        {
                if (par[u][k] != par[v][k])
                {
                        mx = max(mx, dis[u][k]);
                        mx = max(mx, dis[v][k]);
                        u = par[u][k], v = par[v][k];
                }
        }

        return max({mx, dis[u][0], dis[v][0]});
}

struct info
{
        int u, v, w, index;
};

bool comp(info a, info b)
{
        return a.w < b.w;
}

int Parent[N], Rank[N];

void Init(int n)
{
        for (int i = 1 ; i <= n ; i++)
                Rank[i] = 1, Parent[i] = i;
}

int Find_Parent(int v)
{
        if (v == Parent[v])
                return v;

        return Parent[v] = Find_Parent(Parent[v]);
}

void Union(int a, int b)
{
        a = Find_Parent(a);
        b = Find_Parent(b);

        if (a != b)
        {

                if (Rank[a] > Rank[b])
                        swap (a, b);

                Parent[a] = b;
                Rank[b] += Rank[a];
        }
}

int vis[N];
ll ans[N];

void Solve()
{

        int n, m;
        cin >> n >> m;

        vector<info>edge;

        for (int i = 0; i < m; i++)
        {
                int u, v, w;
                cin >> u >> v >> w;
                edge.push_back({u, v, w, i});
        }



        Init(n);

        sort(edge.begin(), edge.end(), comp);


        ll MST = 0;
        for (auto i : edge)
        {
                if (Find_Parent(i.u) == Find_Parent(i.v))
                        continue;
                MST += i.w;
                Union(i.u, i.v);
                vis[i.index] = 1;
        }

        for (auto i : edge)
        {
                if (vis[i.index])
                {
                        node[i.u].push_back({i.v, i.w});
                        node[i.v].push_back({i.u, i.w});
                }
        }


        dfs(1);


        for (auto i : edge)
        {
                if (vis[i.index]) ans[i.index] = MST;
                else
                {
                       
                        ans[i.index] = MST - maxedgepath(i.u, i.v) + i.w;
                }
        }

        for (int i = 0 ; i < m ; i++)
                cout << ans[i] << endl;


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


//https://codeforces.com/contest/609/problem/E