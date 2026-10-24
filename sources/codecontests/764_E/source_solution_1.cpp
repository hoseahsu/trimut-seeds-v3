#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1e4;
int a[maxn], mod;
int b[maxn];
int n;
int pow(int a, int b) {
  if (b == 1) return a;
  int t = pow(a, b >> 1);
  t = 1LL * t * t % mod;
  if (b & 1) t = 1LL * t * a % mod;
  return t;
}
int ny(int a) { return pow(a, mod - 2); }
int ans, dd;
void solve(int a[], int n) {
  if (n == 1) {
    ans = a[1];
    dd = 1;
    return;
  }
  int cc = a[2] - a[1];
  int s = 0;
  for (int i = (1); i <= (n); ++i)
    if (!binary_search(a + 1, a + n + 1, (a[i] + cc) % mod)) ++s;
  cc = 1LL * cc * ny(s) % mod;
  ans = -1, dd = mod - cc;
  for (int i = (1); i <= (n); ++i)
    if (!binary_search(a + 1, a + n + 1, (a[i] + cc) % mod)) {
      if (ans == -1)
        ans = a[i];
      else {
        ans = -1;
        break;
      }
    }
}
void init() {
  scanf("%d%d", &mod, &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  if (n == mod) {
    printf("%d %d\n", 0, 1);
    return;
  }
  sort(a + 1, a + n + 1);
  if (n * 2 > mod) {
    int t = 0;
    for (int i = (0); i <= (mod - 1); ++i)
      if (!binary_search(a + 1, a + n + 1, i)) b[++t] = i;
    solve(b, t);
    if (ans != -1) (ans += 1LL * dd * t % mod) %= mod;
  } else
    solve(a, n);
  if (ans == -1)
    printf("%d\n", ans);
  else
    printf("%d %d\n", ans, dd);
}
int main() {
  init();
  return 0;
}
