#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, inf = 1e9;
int n;
int a[maxn], d[maxn][maxn], f[maxn][maxn][2];
template <typename T>
inline void read(T &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int check(int l, int r, int pos) {
  if (l > r) return 1;
  if (f[l][r][pos] != -1) return f[l][r][pos];
  for (int i = l; i <= r; i++)
    if (d[i][pos ? (l - 1) : (r + 1)] && check(l, i - 1, 0) &&
        check(i + 1, r, 1))
      return f[l][r][pos] = 1;
  return f[l][r][pos] = 0;
}
int main() {
  read(n);
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) d[i][j] = d[j][i] = gcd(a[i], a[j]) != 1;
  }
  for (int i = 1; i <= n; i++)
    if (check(1, i - 1, 0) && check(i + 1, n, 1)) return puts("Yes"), 0;
  puts("No");
}
