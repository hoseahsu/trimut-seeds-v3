#include <bits/stdc++.h>
using namespace std;
int n, x, a[2000010], chafen[2000010], fangan;
long long xz, zeng, ans;
void read(int &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
int abs(int x) { return x >= 0 ? x : -x; }
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) {
      chafen[a[i] - i]++;
      xz += a[i] - i;
      zeng--;
    } else {
      chafen[a[i] + n - i]++;
      xz += i - a[i];
      zeng++;
    }
  }
  ans = xz;
  int ps = 0;
  for (int i = 1; i < n; i++) {
    zeng += chafen[i - 1] * 2 - 2;
    xz += abs(a[n - i + 1] - 1) - abs(a[n - i + 1] - n) + 1 + zeng;
    if (xz < ans) ans = xz, fangan = i;
  }
  printf("%I64d %d\n", ans, fangan);
  return 0;
}
