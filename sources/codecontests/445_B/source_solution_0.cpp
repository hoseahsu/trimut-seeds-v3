#include <bits/stdc++.h>
using namespace std;
long long ans;
int pa[55];
int r[55];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }
int f[55] = {0};
long long mm[55];
void get_2() {
  mm[0] = 1;
  for (int i = 1; i < 55; i++) mm[i] = mm[i - 1] * 2ll;
}
int main() {
  get_2();
  ans = 1;
  int n, m;
  scanf("%d", &n), scanf("%d", &m);
  int x, y;
  for (int i = 0; i < n + 1; i++) {
    pa[i] = i;
    r[i] = 0;
  }
  int k = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &x), scanf("%d", &y);
    x = findset(x);
    y = findset(y);
    if (x != y) {
      if (r[x] < r[y])
        pa[x] = y;
      else {
        pa[y] = x;
        if (r[x] == r[y]) r[x]++;
      }
      k++;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    f[findset(i)]++;
  }
  for (int i = 1; i < n + 1; i++)
    if (f[i]) ans = ans * mm[f[i] - 1];
  printf("%I64d\n", ans);
  return 0;
}
