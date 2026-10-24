#include <bits/stdc++.h>
using namespace std;
int t, n, len;
long long up, down, m, s;
struct node {
  long long u, d, s;
} a[105];
bool flag;
int main() {
  scanf("%d", &t);
  while (t--) {
    flag = true;
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%lld%lld%lld", &a[i].s, &a[i].d, &a[i].u);
    len = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].s == a[len].s) {
        up = a[i].u;
        down = a[i].d;
        if (up < a[len].d || a[len].u < down) {
          flag = false;
          break;
        }
        a[len].u = min(a[len].u, up);
        a[len].d = max(a[len].d, down);
      } else {
        len++;
        a[len].s = a[i].s;
        a[len].u = a[i].u;
        a[len].d = a[i].d;
      }
    }
    if (!flag)
      printf("NO\n");
    else {
      up = down = m;
      s = 0;
      for (int i = 0; i <= len; i++) {
        up = up + (a[i].s - s);
        down = down - (a[i].s - s);
        if (up < a[i].d || a[i].u < down) {
          flag = false;
          break;
        } else {
          up = min(a[i].u, up);
          down = max(a[i].d, down);
        }
        s = a[i].s;
      }
      if (flag)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
