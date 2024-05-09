
/*
* @Author: Zakaria 
* @Date:   2023-12-03 23:07:48
* @Last Modified time: 2024-02-25 11:01:35
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 2000000; // Define the maximum size of your array

struct SegmentTree {
  vector<int> tree;
  vector<int>treemax;
  vector<int>treemin;
  vector<int> lazy;
  vector<int> aa;

  SegmentTree() {
    treemax.resize(4 * N);
    treemin.resize(4 * N);
    treemin.resize(4 * N);
    lazy.resize(4 * N);
    aa.resize(4 * N);
  }

  void build(int node, int b, int e) {
    if (b == e) {
      treemax[node] = 0;
      treemin[node] = 0;
      lazy[node] = 0;
      return;
    }

    int mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    treemax[node] = 0;
    treemin[node] = 0;
    lazy[node] = 0;
    treemax[node] = max(treemax[2 * node], treemax[2 * node + 1]);
    treemin[node] = min(treemin[2 * node], treemin[2 * node + 1]);
  }

  void push(int node, int b, int e) {

    treemax[node] +=  lazy[node];
    treemin[node] +=  lazy[node];

    if (b != e) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  void update(int node, int b, int e, int l, int r, int x) {

    // cout << b << " " << e << " " << l << " " << r << endl;
    if (lazy[node])
      push(node, b, e);

    if (l > e || r < b)
      return;

    if (l <= b && r >= e) {

      lazy[node] +=  x;
      push(node, b, e);
      return;
    }

    int mid = (b + e) >> 1;
    update(2 * node, b, mid, l, r, x);
    update(2 * node + 1, mid + 1, e, l, r, x);

    treemax[node] = max(treemax[2 * node], treemax[2 * node + 1]);
    treemin[node] = min(treemin[2 * node], treemin[2 * node + 1]);
  }

  int querymax(int node, int b, int e, int l, int r) {

    if (lazy[node])
      push(node, b, e);

    if (l > e || r < b)
      return INT_MIN;

    if (l <= b && r >= e) {
      return treemax[node];
    }

    int mid = (b + e) >> 1;
    return max(querymax(2 * node, b, mid, l, r), querymax(2 * node + 1, mid + 1, e, l, r));
  }

  int querymin(int node, int b, int e, int l, int r) {

    if (lazy[node])
      push(node, b, e);

    if (l > e || r < b)
      return INT_MAX;

    if (l <= b && r >= e) {
      return treemin[node];
    }

    int mid = (b + e) >> 1;
    return min(querymin(2 * node, b, mid, l, r), querymin(2 * node + 1, mid + 1, e, l, r));
  }
};

int main() {

  SegmentTree st;

  int n;
  cin >> n;

  st.build(1, 1, n);


  st.update(1, 1, n, 3, 4, 32);
  st.update(1, 1, n, 1, n, -2);
  st.update(1, 1, n, 7, 8, 1);
  st.update(1, 1, n, 1, 2, 5);
  st.update(1, 1, n, 6, 6, -10);

  for (int i = 1 ; i <= n ; i++)
  {
    cout << st.querymax(1, 1, n, i, i) << endl;
  }

  cout << endl;

  cout << st.querymax(1, 1, n, 4, 6) << endl;
  cout << st.querymin(1, 1, n, 4, 6) << endl;

  return 0;
}
