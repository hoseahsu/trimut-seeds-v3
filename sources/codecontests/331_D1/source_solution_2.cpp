#include <bits/stdc++.h>
using namespace std;
const int N = 200005, T = 51;
int sgn(int x) { return x ? (x > 0 ? 1 : -1) : 0; }
struct arrow *null;
struct arrow {
  int sx, sy, tx, ty, dx, dy;
  arrow *to[T];
  long long dis[T];
  arrow() { to[0] = NULL; }
  void init() {
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    dx = sgn(tx - sx);
    dy = sgn(ty - sy);
  }
  void init2() {
    char c;
    scanf("%d%d %c", &sx, &sy, &c);
    tx = sx;
    ty = sy;
    if (c == 'L') dx--;
    if (c == 'R') dx++;
    if (c == 'U') dy++;
    if (c == 'D') dy--;
  }
} a[N];
int id[N];
int n, B, Q;
long long lim[N];
bool cmpx0(int x, int y) {
  return min(a[x].sx, a[x].tx) > min(a[y].sx, a[y].tx);
}
bool cmpx1(int x, int y) {
  return max(a[x].sx, a[x].tx) < max(a[y].sx, a[y].tx);
}
bool cmpy0(int x, int y) {
  return min(a[x].sy, a[x].ty) > min(a[y].sy, a[y].ty);
}
bool cmpy1(int x, int y) {
  return max(a[x].sy, a[x].ty) < max(a[y].sy, a[y].ty);
}
void solve(int dx, int dy, bool (*cmp)(int, int)) {
  for (int i = (int)(1); i <= (int)(n + Q); i++) id[i] = n + Q + 1 - i;
  stable_sort(id + 1, id + n + Q + 1, cmp);
  multimap<int, arrow *> S;
  S.clear();
  for (int i = (int)(1); i <= (int)(n + Q); i++) {
    if (id[i] <= n) {
      int v1, v2;
      if (dy != 0)
        v1 = a[id[i]].sx, v2 = a[id[i]].tx;
      else
        v1 = a[id[i]].sy, v2 = a[id[i]].ty;
      if (v1 > v2) swap(v1, v2);
      auto lo = S.lower_bound(v1);
      auto hi = S.upper_bound(v2);
      for (auto it = lo; it != hi; S.erase(it++)) {
        arrow *ia = it->second;
        ia->to[0] = a + id[i];
        ia->dis[0] = abs(ia->tx - a[id[i]].tx) + abs(ia->ty - a[id[i]].ty);
      }
    }
    if (a[id[i]].dx == dx && a[id[i]].dy == dy)
      S.insert(make_pair(dx ? a[id[i]].ty : a[id[i]].tx, a + id[i]));
  }
  for (auto i : S) {
    i.second->to[0] = null;
    i.second->dis[0] = 1ll << 60;
  }
}
int main() {
  null = a;
  scanf("%d%d", &n, &B);
  for (int i = (int)(1); i <= (int)(n); i++) a[i].init();
  scanf("%d", &Q);
  for (int i = (int)(1); i <= (int)(Q); i++) {
    a[i + n].init2();
    scanf("%lld", &lim[i]);
  }
  solve(-1, 0, cmpx0);
  solve(1, 0, cmpx1);
  solve(0, -1, cmpy0);
  solve(0, 1, cmpy1);
  null->to[0] = null;
  for (int j = (int)(0); j <= (int)(n + Q); j++) {
    assert(a[j].to[0] != NULL);
  }
  for (int i = (int)(1); i <= (int)(T - 1); i++)
    for (int j = (int)(0); j <= (int)(n + Q); j++) {
      a[j].to[i] = a[j].to[i - 1]->to[i - 1];
      a[j].dis[i] =
          min(1ll << 60, a[j].dis[i - 1] + a[j].to[i - 1]->dis[i - 1]);
    }
  for (int i = (int)(1); i <= (int)(Q); i++) {
    arrow *x = a + n + i;
    for (int j = (int)(T - 1); j >= (int)(0); j--)
      if (x->dis[j] <= lim[i]) lim[i] -= x->dis[j], x = x->to[j];
    if (x->to[0] != null && lim[i] >= x->dx * (x->to[0]->tx - x->tx) +
                                          x->dy * (x->to[0]->ty - x->ty))
      lim[i] -= x->dis[0], x = x->to[0];
    printf("%lld %lld\n", min(max(x->tx + x->dx * lim[i], 0ll), 1ll * B),
           min(max(x->ty + x->dy * lim[i], 0ll), 1ll * B));
  }
}
