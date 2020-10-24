struct Segtree {
  int N;
  vector<vector<int>> sg;
  void init(int n) {
    N = n + 1;
    sg.resize(4 * n + 10);
  }
  void build(vector<long long> &a, int node, int low, int high) {
    if (low == high) {
      sg[node] = vector<int>(1, a[low]);
    } else {
      int mid = (low + high) / 2;
      build(a, node * 2, low, mid);
      build(a, node * 2 + 1, mid + 1, high);
      merge(sg[node * 2].begin(), sg[node * 2].end(), sg[node * 2 + 1].begin(), sg[node * 2 + 1].end(), back_inserter(sg[node]));
    }
  }
  int query(int node, int low, int high, int l , int r, int x) {
    if (r < l) {
      return 0;
    }
    if (low == l && high == r) {
      auto k = lower_bound(all(sg[node]), x);
      return (k == sg[node].end() ? 0 : (int)sg[node].size() - (k - sg[node].begin()));
    }
    int mid = (low + high) / 2;
    return (query(2 * node, low, mid, l, min(mid, r), x) + query(2 * node + 1, mid + 1, high, max(l, mid + 1), r, x));
  }
};
