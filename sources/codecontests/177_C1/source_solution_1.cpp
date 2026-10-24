#include <bits/stdc++.h>
using namespace std;
int Belong[2009];
int Cnt[2009];
bool f[2009];
int find(int x) {
  int j, t = x;
  while (x != Belong[x]) {
    x = Belong[x];
  }
  while (t != Belong[t]) {
    j = Belong[t];
    Belong[t] = x;
    t = j;
  }
  return x;
}
void merge(int x, int y) {
  int xx = find(x), yy = find(y);
  if (xx != yy) {
    Belong[xx] = yy;
    Cnt[yy] += Cnt[xx];
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) Belong[i] = i, Cnt[i] = 1;
  scanf("%d", &m);
  int u, v;
  while (m--) {
    scanf("%d%d", &u, &v);
    merge(u, v);
  }
  scanf("%d", &m);
  int x, y;
  memset(f, false, sizeof(f));
  while (m--) {
    scanf("%d%d", &u, &v);
    x = find(u);
    y = find(v);
    if (x == y) f[x] = true;
  }
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (Belong[i] == i && !f[i]) ret = max(ret, Cnt[i]);
  }
  printf("%d\n", ret);
  return 0;
}
