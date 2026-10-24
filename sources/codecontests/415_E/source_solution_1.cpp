#include <bits/stdc++.h>
using namespace std;
long long lrinv[21];
long long rlinv[21];
int n;
int a[1 << 20];
int b[1 << 20];
void mergesort() {
  for (int k = 1; k <= n; k++) {
    int len = 1 << (k - 1);
    for (int j = 0; j < (1 << n); j += 2 * len) {
      int l = 0, r = 0;
      int sl = j, sr = j + len;
      for (int i = 0; i < 2 * len; i++) {
        if (r == len || (l != len && a[sl + l] <= a[sr + r])) {
          b[i] = a[sl + (l++)];
          lrinv[k] += r;
        } else {
          b[i] = a[sr + (r++)];
        }
      }
      l = r = 0;
      for (int i = 0; i < 2 * len; i++) {
        if (l == len || (r != len && a[sr + r] <= a[sl + l])) {
          r++;
          rlinv[k] += l;
        } else {
          l++;
        }
      }
      memcpy(a + j, b, sizeof(int) * (2 * len));
    }
  }
}
bool status[21];
long long cans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  scanf("%d", &n);
  for (int i = 0; i < (int)(1 << n); i++) scanf("%d", a + i);
  mergesort();
  for (int i = 0; i < (int)(n + 1); i++) cans += lrinv[i];
  int m;
  scanf("%d", &m);
  for (int _ = 0; _ < (int)(m); _++) {
    int q;
    scanf("%d", &q);
    for (int i = 0; i <= q; i++) {
      if (!status[i]) {
        cans -= lrinv[i];
        cans += rlinv[i];
      } else {
        cans -= rlinv[i];
        cans += lrinv[i];
      }
      status[i] = !status[i];
    }
    printf("%lld\n", cans);
  }
  return 0;
}
