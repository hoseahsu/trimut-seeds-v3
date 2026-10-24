#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
map<int, int> mp;
int a[maxn], g[maxn], h[maxn];
int main() {
  int n;
  scanf("%d", &n);
  int tot = 0;
  mp.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (mp[a[i]] == 0) {
      mp[a[i]] = ++tot;
      h[tot] = a[i];
    }
  }
  for (int i = 1; i <= n; i++) g[i] = mp[a[i]];
  bool flag = true;
  for (int i = 1; i <= tot; i++) {
    if (g[h[i]] != i) {
      flag = false;
      break;
    }
  }
  if (!flag)
    puts("-1");
  else {
    printf("%d\n", tot);
    for (int i = 1; i <= n; i++) printf("%d%c", g[i], i != n ? ' ' : '\n');
    for (int i = 1; i <= tot; i++) printf("%d%c", h[i], i != tot ? ' ' : '\n');
  }
  return 0;
}
