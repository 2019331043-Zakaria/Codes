/*
* @Author: Zakaria
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2024-01-04 16:24:02
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
  int mn, cnt;
};

struct SegmentTree {
#define lc (node << 1)
#define rc ((node << 1) | 1)

  vector<pr> tree;
  vector<ll> lazy;

  SegmentTree() {
    tree.resize(4 * N);
    lazy.resize(4 * N);
  }

  void pull(int node)
  {
    int curmin = min(tree[lc].mn, tree[rc].mn);

    if (curmin == tree[lc].mn && curmin == tree[rc].mn)
    {
      tree[node].mn = curmin;
      tree[node].cnt = tree[lc].cnt + tree[rc].cnt;
    }
    else if (curmin == tree[lc].mn)
    {
      tree[node].mn = curmin;
      tree[node].cnt = tree[lc].cnt;
    }
    else
    {
      tree[node].mn = curmin;
      tree[node].cnt = tree[rc].cnt;
    }
  }

  pr combine(pr a, pr b)
  {
    int curmin = min(a.mn, b.mn);
    if (curmin == a.mn && curmin == b.mn)
    {
      return {curmin, a.cnt + b.cnt};
    }
    else if (curmin == a.mn)
    {
      return {curmin, a.cnt};
    }
    else
    {
      return {curmin, b.cnt};
    }
  }

  void build(ll node, ll b, ll e) {

    if (b == e) {
      tree[node].mn = a[b];
      tree[node].cnt = 1;
      lazy[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    lazy[node] = 0;
    tree[node].mn = INT_MAX;
    tree[node].cnt = 0;

    pull(node);

    //tree[node] = min(tree[lc] , tree[rc]);
  }

  void push(ll node, ll b, ll e) {

    if (!lazy[node])
      return ;

    tree[node].mn = lazy[node];
    tree[node].cnt = 1;

    if (b != e) {
      lazy[lc] = lazy[node];
      lazy[rc] = lazy[node];
    }

    lazy[node] = 0;
  }

  void update(ll node, ll b, ll e, ll l, ll r, ll x) {

    push(node, b, e);

    if (l > e || r < b)
      return;

    if (l <= b && r >= e) {

      tree[node].mn =  x;
      tree[node].cnt = 1;
      push(node, b, e);
      lazy[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    update(lc, b, mid, l, r, x);
    update(rc, mid + 1, e, l, r, x);

    pull(node);

  }

  pr query(ll node, ll b, ll e, ll l, ll r) {

    push(node, b, e);

    if (l > e || r < b)
      return {INT_MAX, 1};

    if (l <= b && r >= e) {
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

  while (k--)
  {
    int t;
    cin >> t;

    if (t == 1)
    {
      ll indx, x;
      cin >> indx >> x;
      indx++;
      st.update(1, 1, n, indx, indx, x);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l++, r;

      pr lol = st.query(1, 1, n, l, r);
      cout << lol.mn << " " << lol.cnt << endl;
      //cout << st.query(1, 1 , n, l, r) << endl;
    }


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