#include <bits/stdc++.h>
using namespace std;
const int N = 201000;
int n, k, A, B, q;
int a[N], b[N];
int c[2][N];
void update(int wh, int i, int v) {
  for (; i <= n; i += i & -i) c[wh][i] += v;
}
int query(int wh, int i) {
  int res = 0;
  for (; i; i -= i & -i) res += c[wh][i];
  return res;
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &A, &B, &q);
  while (q--) {
    int op, i, d;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &i, &d);
      if (a[i] + d < A)
        update(0, i, d), a[i] += d;
      else
        update(0, i, A - a[i]), a[i] = A;
      if (b[i] + d < B)
        update(1, i, d), b[i] += d;
      else
        update(1, i, B - b[i]), b[i] = B;
    } else {
      scanf("%d", &i);
      printf("%d\n", query(0, n) - query(0, i + k - 1) + query(1, i - 1));
    }
  }
  return 0;
}
