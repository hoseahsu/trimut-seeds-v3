#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, d;
};
node t[105];
bool cmp(node a, node b) {
  if (a.y != b.y) return a.y < b.y;
  if (a.x != b.x) return a.x > b.x;
  return a.d < b.d;
}
int tmp[10000005] = {0};
int ans[105];
int main() {
  int n;
  cin >> n;
  memset(t, 0, sizeof(t));
  memset(tmp, 0, sizeof(tmp));
  for (int i = 1; i <= n; i++) {
    cin >> t[i].x >> t[i].y;
    t[i].d = i;
  }
  sort(t + 1, t + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = t[i].x; j <= t[i].y; j++) {
      if (tmp[j] == 1) continue;
      tmp[j] = 1;
      ans[t[i].d] = j;
      break;
    }
  }
  cout << ans[1];
  for (int i = 2; i <= n; i++) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}
