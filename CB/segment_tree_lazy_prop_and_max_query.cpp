/*
* @Author: Zakaria 
* @Date:   2024-01-08 15:52:14
* @Last Modified time: 2024-01-08 15:52:25
*/

struct SegmentTree
{
  vector<ll> tree;
  vector<ll> lazy;

  SegmentTree() {
    tree.resize(4 * N);
    lazy.resize(4 * N);

    fill(tree.begin(), tree.end(), 0);
    fill(lazy.begin(), lazy.end(), 0);
  }

  void build(ll node, ll b, ll e) {


    if (b == e) {

      tree[node] = a[b];
      return;
    }

    ll mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);

    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
  }

  void push(ll node, ll b, ll e) {

    if (lazy[node] == 0)
      return ;

    tree[node] += lazy[node];

    if (b != e) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  void update(ll node, ll b, ll e, ll l, ll r, ll x) {


    push(node, b, e);

    if (l > e || r < b)
      return;

    if (l <= b && r >= e) {

      lazy[node] += x;

      push(node, b, e);

      return;
    }

    ll mid = (b + e) >> 1;
    update(2 * node, b, mid, l, r, x);
    update(2 * node + 1, mid + 1, e, l, r, x);

    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
  }

  ll query(ll node, ll b, ll e, ll l, ll r)
  {

    push(node, b, e);

    if (l > e || r < b)
      return INT_MAX;

    if (l <= b && r >= e) 
    {
      return tree[node];
    }

    ll mid = (b + e) >> 1;
    return min(query(2 * node, b, mid, l, r) , query(2 * node + 1, mid + 1, e, l, r));
  }
};