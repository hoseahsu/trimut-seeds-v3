#include <bits/stdc++.h>
using namespace std;
int fa[1000001], m, n, q, i, v, r, c;
int find(int x) {
  if (x == fa[x]) {
    return x;
  }
  fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  cin >> n >> m >> q;
  for (i = 1; i <= m + n; i++) {
    fa[i] = i;
  }
  for (i = 1; i <= q; i++) {
    cin >> r >> c;
    r = find(r);
    c = find(c + n);
    fa[r] = c;
  }
  for (i = 1; i <= m + n; i++) {
    if (i == fa[i]) {
      v++;
    }
  }
  cout << v - 1 << endl;
}
