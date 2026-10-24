#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r;
  int id;
};
int l, r;
int n;
node a[110];
set<int> event;
int ans[110];
bool cmp(const node &x, const node &y) {
  return x.l < y.l || (x.l == y.l && x.r < y.r);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    event.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].l, &a[i].r);
      a[i].id = i;
    }
    sort(a, a + n, cmp);
    for (int i = n - 1; i >= 0; i--) {
      l = a[i].l;
      r = a[i].r;
      for (int j = r; j >= l; j--)
        if (!event.count(j)) {
          ans[a[i].id] = j;
          event.insert(j);
          break;
        }
    }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
