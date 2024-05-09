struct SegmentTree {
  vector<ll> tree;
  vector<ll> lazy;

  SegmentTree() {
    tree.resize(4 * N);
    for (int i = 0 ; i < tree.size() ; i++)
      tree[i] = 0;

    lazy.resize(4 * N);
    for (int i = 0 ; i < tree.size() ; i++)
      lazy[i] = 0;

  }

  void build(ll node, ll b, ll e) {

    if (b == e) {
      tree[node] = a[b];
      lazy[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
  }

  void push(ll node, ll b, ll e) {

    if (!lazy[node])
      return ;

    tree[node] = lazy[node];

    if (b != e) {
      lazy[2 * node] = lazy[node];
      lazy[2 * node + 1] = lazy[node];
    }

    lazy[node] = 0;
  }

  void update(ll node, ll b, ll e, ll l, ll r, ll x) {

    push(node, b, e);

    if (l > e || r < b)
      return;

    if (l <= b && r >= e) {
      lazy[node] = x;
      push(node, b, e);
      lazy[node] = 0;
      return;
    }

    ll mid = (b + e) >> 1;
    update(2 * node, b, mid, l, r, x);
    update(2 * node + 1, mid + 1, e, l, r, x);

    tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
  }

  ll query(ll node, ll b, ll e, ll l, ll r) {

    push(node, b, e);

    if (l > e || r < b)
      return 0;

    if (l <= b && r >= e) {
      return tree[node];
    }

    ll mid = (b + e) >> 1;
    return max(query(2 * node, b, mid, l, r) , query(2 * node + 1, mid + 1, e, l, r));
  }
};
