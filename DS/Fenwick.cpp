struct Fenwick {
  vector<int> BIT;
  int N;
  Fenwick(int n) {
    N = n + 2;
    BIT.resize(N + 10);
  }
  void reset() {
    for (int i = 0; i <= N; i++) {
      BIT[i] = 0;
    }
  }
  void add(int r, int value) {
    for (int i = r; i <= N; i = i | (i + 1)) {
      BIT[i] += value;
    }
  }
  int qry(int r) {
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
      ans += BIT[i];
    }
    return ans;
  }
};
