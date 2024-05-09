struct SegmentTree {
  vector<ll> tree;
  SegmentTree() {
    tree.resize(4 * N);
    for (int i = 0 ; i < tree.size() ; i++)
      tree[i] = 0;

  }

  void build(ll node, ll b, ll e) {

    if (b == e) {
      tree[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    tree[node] = (tree[2 * node] + tree[2 * node + 1]);
  }

  void update(ll node, ll b, ll e, ll l, ll x) {

    if (l > e || l < b)
      return;

    if (b == e && b == l)
    {
      tree[node] = x;
      return;
    }

    ll mid = (b + e) >> 1;
    update(2 * node, b, mid, l, x);
    update(2 * node + 1, mid + 1, e, l, x);

    tree[node] = (tree[2 * node] + tree[2 * node + 1]);
  }

  ll query(ll node, ll b, ll e, ll l, ll r) {

    if (l > e || r < b)
      return 0;

    if (l <= b && r >= e) {
      return tree[node];
    }

    ll mid = (b + e) >> 1;
    return (query(2 * node, b, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r));
  }
};
SegmentTree st;