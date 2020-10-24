int power(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y >>= 1;
    x = x * x;
  }
  return res;
}
