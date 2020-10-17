vector<int> prefix_function(const string &s) {
  vector<int> z((int)s.size());
  for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
    if (i <= r) {
      z[i] = min(z[i - 1], r - i + 1);
    }
    while (i + z[i] < (int)s.size() and s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}
