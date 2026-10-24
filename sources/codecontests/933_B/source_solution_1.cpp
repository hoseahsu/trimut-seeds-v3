#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const double eps = 1e-12;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
const int N = 100;
long long k, p;
int ans[N], ret = 0;
signed main() {
  read(p);
  read(k);
  while (p) {
    ans[++ret] = p % k;
    if (ans[ret] < 0) {
      ans[ret] += k;
      p -= k;
    }
    p /= -k;
  }
  printf("%d\n", ret);
  for (int i = 1; i <= ret; i++) printf("%d ", ans[i]);
  return 0;
}
