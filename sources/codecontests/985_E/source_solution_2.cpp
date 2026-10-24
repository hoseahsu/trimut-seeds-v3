#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
void Print(int *a, int n) {
  for (int i = 1; i < n; i++) printf("%d ", a[i]);
  printf("%d\n", a[n]);
}
int f[N], n, k, d, a[N];
bool dp[N];
void upd(int x, int v) {
  while (x <= n + 1) f[x] += v, x += x & (-x);
}
int que(int x) {
  int s = 0;
  while (x) s += f[x], x -= x & (-x);
  return s;
}
int que(int l, int r) {
  if (l > r) return 0;
  l++, r++;
  return que(r) - que(l - 1);
}
int main() {
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  dp[0] = 1;
  upd(1, 1);
  for (int i = 1, l = 0; i <= n; i++) {
    while (a[i] - a[l + 1] > d) l++;
    dp[i] = (que(l, i - k) >= 1);
    if (dp[i]) upd(i + 1, 1);
  }
  puts(dp[n] ? "YES" : "NO");
  return 0;
}
