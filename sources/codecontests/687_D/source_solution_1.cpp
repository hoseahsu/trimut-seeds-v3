#include <bits/stdc++.h>
using namespace std;
int n, m, q, dsu[2005];
map<pair<int, int>, int> ans;
struct edge {
  int x, y, z, u;
  bool operator<(const edge b) const { return z < b.z; }
} e[500005];
int find_(int x) { return x == dsu[x] ? x : dsu[x] = find_(dsu[x]); }
void unite_(int x, int y) { dsu[find_(x)] = dsu[find_(y)]; }
signed main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m;
       scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z), e[i].u = i, i++)
    ;
  sort(e + 1, e + 1 + m);
  while (q--) {
    int el, er;
    scanf("%d%d", &el, &er);
    for (int i = 1; i <= n * 2; i++) dsu[i] = i;
    bool flag = 0;
    for (int i = m; i >= 1; i--)
      if (e[i].u >= el && e[i].u <= er) {
        int fx = find_(e[i].x), fy = find_(e[i].y);
        if (fx == fy) {
          printf("%d\n", e[i].z);
          flag = 1;
          break;
        }
        unite_(e[i].x, e[i].y + n), unite_(e[i].x + n, e[i].y);
      }
    if (!flag) puts("-1");
  }
  return 0;
}
