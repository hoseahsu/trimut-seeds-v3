#include <bits/stdc++.h>
using namespace std;
const int N = 330;
long long x, y, a[N], mem[30][2][10][10];
long long dp(int i, bool q, int first, int last) {
  if (i == 21) {
    return last == first;
  }
  long long &ret = mem[i][q][first][last];
  if (ret != -1) return ret;
  ret = 0;
  if (q) {
    if (first != 0)
      for (int j = 0; j <= a[i]; j++) ret += dp(i + 1, j == a[i], first, j);
    else
      for (int j = 0; j <= a[i]; j++) ret += dp(i + 1, j == a[i], j, j);
  } else {
    if (first != 0)
      for (int j = 0; j <= 9; j++) ret += dp(i + 1, 0, first, j);
    else
      for (int j = 0; j <= 9; j++) ret += dp(i + 1, 0, j, j);
  }
  return ret;
}
int main() {
  scanf("%lld%lld", &x, &y);
  for (int i = 20; i >= 0; i--) {
    a[i] = y % 10;
    y /= 10;
  }
  memset(mem, -1, sizeof mem);
  long long ans = dp(0, 1, 0, 0);
  x--;
  for (int i = 20; i >= 0; i--) {
    a[i] = x % 10;
    x /= 10;
  }
  memset(mem, -1, sizeof mem);
  ans -= dp(0, 1, 0, 0);
  printf("%lld", ans);
}
