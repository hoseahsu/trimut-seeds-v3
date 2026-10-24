#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, t, id;
} a[200002];
int n, h, m, k, i, j;
int read() {
  char c = getchar();
  int w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
int cmp1(const node &a, const node &b) {
  if (a.x == b.x) return a.t < b.t;
  return a.x < b.x;
}
int cmp2(const node &a, const node &b) { return a.t < b.t; }
int main() {
  n = read();
  h = read();
  m = read();
  k = read();
  for (i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].t = read() % (m / 2);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp2);
  for (i = 1; i <= n; i++) a[n + i] = (node){0, a[i].t + m / 2, a[i].id};
  int ans = 1 << 30, tim, l, r;
  for (i = n + 1, j = 1; i <= 2 * n; i++) {
    while (a[i].t - a[j].t >= k && j <= 2 * n) j++;
    if (i - j < ans) ans = i - j, l = j, r = i - 1, tim = a[i].t;
  }
  printf("%d %d\n", ans, tim % (m / 2));
  if (ans != 0) {
    for (i = l; i <= r; i++) printf("%d ", a[i].id);
    puts("");
  }
  return 0;
}
