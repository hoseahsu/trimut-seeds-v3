#include <bits/stdc++.h>
using namespace std;
int n, to[200050], nxt[200050], fir[100050], ans, t1, t2, tot, siz[100050],
    son[100050], mx[100050], rt, rt2, dep[100040];
void ade(int x, int y) {
  to[++tot] = y;
  nxt[tot] = fir[x];
  fir[x] = tot;
}
void find(int x, int fa) {
  siz[x] = 1;
  mx[x] = 0;
  dep[x] = dep[fa] + 1;
  bool bb = 1;
  for (int k = fir[x]; k; k = nxt[k]) {
    if (to[k] == fa) continue;
    find(to[k], x);
    mx[x] = max(mx[x], siz[to[k]]);
    son[x] = son[to[k]];
    siz[x] += siz[to[k]];
    bb = 0;
  }
  if (bb) son[x] = x;
  mx[x] = max(mx[x], n - siz[x]);
  if (mx[x] < mx[rt])
    rt = x, rt2 = 0;
  else if (mx[x] == mx[rt])
    rt2 = x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    mx[0] = n;
    rt = rt2 = 0;
    tot = 0;
    memset(fir, 0, sizeof(fir));
    for (int i = 1; i <= n - 1; i++) {
      int x, y;
      cin >> x >> y;
      ade(x, y);
      ade(y, x);
    }
    find(1, 0);
    if (rt2 == 0)
      cout << 1 << " " << to[fir[1]] << endl << 1 << " " << to[fir[1]] << endl;
    else {
      if (dep[rt] < dep[rt2]) swap(rt, rt2);
      cout << son[rt] << " " << to[fir[son[rt]]] << endl
           << rt2 << " " << son[rt] << endl;
    }
  }
  return 0;
}
