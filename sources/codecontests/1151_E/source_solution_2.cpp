#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline long long readll() {
  long long x(0), op(1);
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * op;
}
const int sz = 2e5 + 9;
long long a[sz], n;
long long solve(long long a, long long b) {
  if (a == 0 || a == b) return 0;
  int l = 1, r = n;
  if (b) {
    if (b < a)
      l = b + 1;
    else
      r = b - 1;
  }
  return (a - l + 1) * (r - a + 1);
}
int main() {
  n = readll();
  for (int i = 1; i < n + 1; ++i) a[i] = readll();
  a[0] = a[n + 1] = 0;
  long long ans = 0;
  for (int i = 0; i < n + 1; ++i) {
    ans += solve(a[i], a[i + 1]);
    ans += solve(a[i + 1], a[i]);
  }
  cout << ans / 2 << endl;
  return 0;
}
