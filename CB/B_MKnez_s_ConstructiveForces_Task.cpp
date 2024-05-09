#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9 + 9;
int a[N], b[N], c[N];
int t[N][18];

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  int t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == inf) return;
    t[n] = min(t[n], lazy[n]);
    if (b != e) {
      lazy[lc] = min(lazy[lc], lazy[n]);
      lazy[rc] = min(lazy[rc], lazy[n]);
    }
    lazy[n] = inf;
  }
  inline int combine(int a,int b) {
    return min(a, b);
  }
  inline void pull(int n) {
    t[n] = min(t[lc], t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = inf;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, int v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return inf; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}st;

void build(int n) {
  for(int i = 1; i <= n; ++i) t[i][0] = b[i];
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      t[i][k] = max(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return max(t[l][k], t[r - (1 << k) + 1][k]);
}
bool solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > a[i]) ok = false;
  }
  int m; cin >> m;
  map<int, int> cnt;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
  }
  if (!ok) return false;
  for (int i = 1; i <= m; i++) {
    cnt[c[i]]++;
  }

  build(n);
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    a[i] = st.query(1, 1, n, i, i);
    cout<<i<<" "<<a[i]<<endl;
    if (b[i] < a[i]) {
      int x = b[i];
      if (cnt[x] == 0) return false;
      int l = i, r = i;
      int L = i, R = n;
      while (L <= R) {
        int mid = L + R >> 1;
        if (query(i, mid) <= x) {
          r = mid;
          L = mid + 1;
        }
        else {
          R = mid - 1;
        }
      }

      cout<<i<<" to "<<r<<endl;
      // for (int j = i; j <= n; j++) {
      //   if (b[j] > x) break;
      //   r = j;
      // }
      cnt[x]--;
      // for (int j = l; j <= r; j++) {
      //   a[j] = min(a[j], x);
      // }
      st.upd(1, 1, n, l, r, x);
    }
//    a[i] = st.query(1, 1, n, i, i);
 
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    if (solve()) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}