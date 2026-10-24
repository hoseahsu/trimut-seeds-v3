#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
vector<int> e[N];
int q[2][N], vis[N];
int deg[N];
int Q(int c1, int c2) {
  for (int i = (int)(1); i <= (int)(n); i++) vis[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) deg[i] = e[i].size();
  int h[2], t[2];
  h[0] = t[0] = h[1] = t[1] = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (deg[i] <= 1) {
      if (a[i] == c2)
        q[1][++t[1]] = i;
      else
        q[0][++t[0]] = i;
      vis[i] = 1;
    }
  for (int i = (int)(1); i <= (int)(n); i++) {
    int p1 = (i & 1) ^ 1, p2 = p1 ^ 1;
    while (h[p1] != t[p1]) {
      int x = q[p1][++h[p1]];
      for (auto i : e[x])
        if (!vis[i] && (--deg[i]) <= 1) {
          vis[i] = 1;
          if (a[i] == 0 || a[i] == (p1 ? c2 : c1))
            q[p1][++t[p1]] = i;
          else
            q[p2][++t[p2]] = i;
        }
    }
    h[p1] = t[p1] = 0;
    if (!t[p2]) return i;
  }
}
void solve() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) e[i].resize(0);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  printf("%d\n", min(Q(1, 2), Q(2, 1)));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
