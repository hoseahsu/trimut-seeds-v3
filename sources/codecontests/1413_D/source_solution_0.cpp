#include <bits/stdc++.h>
using std::cin;
using std::min;
using std::pair;
using std::sort;
const int MAXN = 2e5 + 10;
int n, a[MAXN];
bool vis[MAXN];
int nxt[MAXN];
int get_nxt(int u) { return nxt[u] == u ? u : nxt[u] = get_nxt(nxt[u]); }
int h, t;
pair<int, int> q[MAXN];
int main() {
  scanf("%d", &n);
  char op;
  for (register int i = 1; i <= n * 2; ++i) {
    cin >> op;
    if (op == '+')
      vis[i] = 1;
    else
      scanf("%d", &a[i]);
  }
  vis[n * 2 + 1] = 1;
  for (register int i = 0; i <= n * 2 + 1; ++i) nxt[i] = i + !vis[i];
  q[h = t = n] = pair<int, int>(0x3f3f3f3f, 0);
  for (register int i = 1, j, k; i <= n * 2; ++i)
    if (!vis[i]) {
      j = lower_bound(q + h, q + t + 1, pair<int, int>(a[i], i))->second;
      k = get_nxt(j);
      if (k > i) {
        printf("NO\n");
        return 0;
      } else {
        a[k] = a[i];
        nxt[k] = k + 1;
      }
      while (a[i] > q[h].first) ++h;
      q[--h] = pair<int, int>(a[i], i);
    }
  printf("YES\n");
  for (register int i = 1; i <= n * 2; ++i)
    if (vis[i]) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
