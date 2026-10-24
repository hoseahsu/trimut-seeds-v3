#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
int a[1001005], b[1001005], pp[4];
int t[1001005 * 21], cnt, root[1001005], lc[1001005 * 21], rc[1001005 * 21];
void update(int rt, int &cur, int l, int r, int v) {
  cur = ++cnt;
  if (l + 1 == r) {
    t[cur] = t[rt] + 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (v <= mid) {
    update(lc[rt], lc[cur], l, mid, v);
    rc[cur] = rc[rt];
  } else {
    update(rc[rt], rc[cur], mid, r, v);
    lc[cur] = lc[rt];
  }
  t[cur] = t[lc[cur]] + t[rc[cur]];
}
int qy(int rt, int cur, int l, int r, int L, int R) {
  if (R <= l || r <= L) return 0;
  if (L <= l && r <= R) {
    return t[cur] - t[rt];
  }
  int mid = (l + r) >> 1;
  int x = qy(lc[rt], lc[cur], l, mid, L, R);
  int y = qy(rc[rt], rc[cur], mid, r, L, R);
  return x + y;
}
int f(int x, int z) { return (z - 1 + x) % n + 1; }
int main() {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", a + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", &k);
    b[k] = i;
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    update(root[i - 1], root[i], 0, n, b[a[i]]);
  }
  int x = 0;
  scanf("%d", &m);
  for (int(i) = 0; (i) < (int)(m); (i)++) {
    for (int(j) = 0; (j) < (int)(4); (j)++) {
      scanf("%d", pp + j);
      pp[j] = f(x, pp[j]);
    }
    int l1 = min(pp[0], pp[1]);
    int r1 = max(pp[0], pp[1]);
    int l2 = min(pp[2], pp[3]);
    int r2 = max(pp[2], pp[3]);
    printf("%d\n", x = qy(root[l1 - 1], root[r1], 0, n, l2 - 1, r2));
    x++;
  }
  return 0;
}
