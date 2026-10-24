#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxm = 500005;
struct node {
  int x, ord;
} p[maxm];
int mi[4], mx[4];
long long f[maxm];
int main(void) {
  int i, n, rev, pre1, pre2, cnt, j, k, sum;
  long long ans = 0;
  char ch;
  scanf("%d", &n);
  for (i = 1; i <= 3; i++) {
    mi[i] = INF;
    mx[i] = -INF;
  }
  for (i = 1; i <= n; i++) {
    scanf("%d %c", &p[i].x, &ch);
    if (ch == 'R') {
      p[i].ord = 1;
      mx[1] = max(p[i].x, mx[1]);
      mi[1] = min(p[i].x, mi[1]);
    } else if (ch == 'P') {
      p[i].ord = 3;
      mx[3] = max(p[i].x, mx[3]);
      mi[3] = min(p[i].x, mi[3]);
    } else {
      p[i].ord = 2;
      mx[2] = max(p[i].x, mx[2]);
      mi[2] = min(p[i].x, mi[2]);
    }
  }
  if (mx[3] == -INF) {
    if (mx[1] != -INF) ans += mx[1] - mi[1];
    if (mx[2] != -INF) ans += mx[2] - mi[2];
    printf("%lld\n", ans);
    return 0;
  }
  ans = mx[3] - mi[3];
  if (mx[1] != -INF) {
    cnt = rev = 0;
    pre1 = pre2 = -1;
    for (i = 1; i <= n; i++) {
      if (p[i].ord == 3) {
        if (pre2 != -1) {
          ans += p[i].x - p[pre2].x;
          rev = max(rev, p[i].x - p[pre2].x);
        }
        if (pre1 != -1) {
          if (rev) f[++cnt] = p[i].x - p[pre1].x - rev;
          ans -= rev;
        }
        pre1 = pre2 = i;
        rev = 0;
      } else if (p[i].ord == 1) {
        if (pre2 != -1) {
          ans += p[i].x - p[pre2].x;
          rev = max(rev, p[i].x - p[pre2].x);
        }
        pre2 = i;
      }
    }
  }
  if (mx[3] != -INF) {
    cnt = rev = 0;
    pre1 = pre2 = -1;
    for (i = 1; i <= n; i++) {
      if (p[i].ord == 3) {
        if (pre2 != -1) {
          ans += p[i].x - p[pre2].x;
          rev = max(rev, p[i].x - p[pre2].x);
        }
        if (pre1 != -1) {
          if (rev) f[++cnt] += p[i].x - p[pre1].x - rev;
          if (f[cnt] > p[i].x - p[pre1].x) ans -= f[cnt] - p[i].x + p[pre1].x;
          ans -= rev;
        }
        pre1 = pre2 = i;
        rev = 0;
      } else if (p[i].ord == 2) {
        if (pre2 != -1) {
          ans += p[i].x - p[pre2].x;
          rev = max(rev, p[i].x - p[pre2].x);
        }
        pre2 = i;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
