#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn];
int a[maxn];
int vis1[maxn];
int main() {
  int n;
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 1;
  }
  memset(vis1, 0, sizeof(vis1));
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 1 && a[i] <= n && !vis1[a[i]]) {
      vis1[a[i]] = 1;
      continue;
    }
    while (vis[cnt]) cnt++;
    a[i] = cnt;
    vis1[a[i]] = 1;
    vis[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  cout << endl;
  return 0;
}
