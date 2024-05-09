/*
* @Author: Zakaria 
* @Date:   2024-01-04 23:19:56
* @Last Modified time: 2024-01-04 23:20:05
*/
/*
* @Author: Zakaria
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2024-01-04 23:18:23
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         100002
typedef long long ll;
using namespace std;

const ll N = 500000; // Define the maximum size of your array
ll a[N];

struct pr {

  ll prf = 0, suf = 0, sum = 0 , mx = 0;
};

struct SegmentTree {

#define lc (node << 1)
#define rc ((node << 1) | 1)

  vector<pr> tree;
  vector<ll> lazy;

  SegmentTree() 
  {
    tree.resize(4 * N);
    lazy.resize(4 * N);
  }

  pr combine(pr a, pr b)
  {

    pr c;

    c.prf = max(a.sum + b.prf, a.prf);
    c.suf = max(b.suf, b.sum + a.suf);
    c.sum = a.sum + b.sum;
    c.mx  = max({a.mx, b.mx, a.suf + b.prf});

    return c;

  }

  void build(ll node, ll b, ll e) 
  {

    if (b == e)
    {

      tree[node].sum = a[b];
      tree[node].prf = max(0LL, a[b]);
      tree[node].suf = max(0LL, a[b]);
      tree[node].mx = max(0LL, a[b]);
      lazy[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);

    lazy[node] = 0;

    tree[node] =  combine(tree[lc], tree[rc]);
  }

  void update(ll node, ll b, ll e, ll l,  ll x) {

    if (l > e || l < b)
      return;

    if (b == e && b == l)
    {

      tree[node] = {max(x, 0LL), max(x, 0LL), x,  max(x, 0LL)};
      return;
    }

    ll mid = (b + e) >> 1;
    update(lc, b, mid, l, x);
    update(rc, mid + 1, e, l, x);

    tree[node] =  combine(tree[lc], tree[rc]);
  }

  pr query(ll node, ll b, ll e, ll l, ll r) {

    if (l > e || r < b)
      return {0, 0, 0, 0};

    if (l <= b && r >= e) 
    {
      return tree[node];
    }

    ll mid = (b + e) >> 1;
    return combine(query(lc, b, mid, l, r) , query(rc, mid + 1, e, l, r));
  }
};

void Solve()
{

  int n, k;
  cin >> n >> k;

  for (int i = 1 ; i <= n ; i++)
    cin >> a[i];

  SegmentTree st;
  
  st.build(1, 1, n);

  cout << st.query(1, 1, n, 1, n).mx << endl;

  while (k--)
  {
    ll idx, x;
    cin >> idx >> x;

    idx++;

    st.update(1, 1, n,  idx, x);

    auto it = st.query(1, 1, n, 1, n);

    cout << it.mx << endl;
  }


}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt = 1;
  //   cin>>tt;

  while (tt--)
  {

    Solve();
  }


  return 0;

}