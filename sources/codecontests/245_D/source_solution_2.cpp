#include <bits/stdc++.h>
using namespace std;
long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const long long maxn = 100 + 10;
const long long inf = 1e9 + 10;
const long long mod = 1e9 + 7;
long long b[maxn][maxn], a[maxn];
int32_t main() {
  long long n = in();
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      b[i][j] = in();
      if (i - j)
        for (long long x = 0; x < 30; x++) {
          if (b[i][j] >> x & 1) a[i] |= (1 << x), a[j] |= (1 << x);
        }
    }
  }
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
}
