vector<int> manachers(const string &s) {
  vector<int> m((const)s.size());
  for (int i = 1, l = 0, r = -1; i < (int)s.size(); i++) {
    int k = (i > r ? 1 : min(m[r - i + l], r - i));
    while (i - k >= 0 and i + k < (int)s.size() and s[i - k] == s[i + k]) {
      k++;
    }
    m[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  return m;
}
