#include <bits/stdc++.h>
using namespace std;
struct point {
  int p, op;
} maxn, minn;
int main() {
  int n;
  int a[105];
  while (~scanf("%d", &n)) {
    maxn.op = 0;
    minn.op = 105;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (maxn.op < a[i]) {
        maxn.op = a[i];
        maxn.p = i;
      }
      if (minn.op > a[i]) {
        minn.op = a[i];
        minn.p = i;
      }
    }
    if (abs(maxn.p - minn.p) == n - 1) {
      printf("%d\n", n - 1);
    } else {
      int a = abs(1 - maxn.p);
      int b = abs(1 - minn.p);
      int c = abs(n - maxn.p);
      int d = abs(n - minn.p);
      a = max(a, b);
      a = max(a, c);
      a = max(a, d);
      printf("%d\n", a);
    }
  }
  return 0;
}
