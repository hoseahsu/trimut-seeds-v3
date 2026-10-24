#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 4;
struct node {
  int l, r, id;
  int pos;
};
bool cmp(node c, node d) {
  if (c.pos != d.pos) return c.l < d.l;
  return c.r < d.r;
}
node qu[N];
int n, m, k;
int b[N], num[2 * N];
long long ans[N];
void solve() {
  memset(num, 0, sizeof(num));
  int le = 1, ri = 0;
  long long temp = 0;
  num[0] = 1;
  for (int i = 1; i <= m; i++) {
    while (ri < qu[i].r) {
      ri++;
      temp += num[b[ri] ^ k];
      num[b[ri]]++;
    }
    while (ri > qu[i].r) {
      num[b[ri]]--;
      temp -= num[b[ri] ^ k];
      ri--;
    }
    while (le > qu[i].l) {
      le--;
      temp += num[b[le - 1] ^ k];
      num[b[le - 1]]++;
    }
    while (le < qu[i].l) {
      num[b[le - 1]]--;
      temp -= num[b[le - 1] ^ k];
      le++;
    }
    ans[qu[i].id] = temp;
  }
}
int main() {
  while (~scanf("%d%d%d", &n, &m, &k)) {
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      b[i] ^= b[i - 1];
    }
    int s = sqrt(n);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &qu[i].l, &qu[i].r);
      qu[i].id = i;
      qu[i].pos = qu[i].l / s;
    }
    sort(qu + 1, qu + m + 1, cmp);
    solve();
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}
