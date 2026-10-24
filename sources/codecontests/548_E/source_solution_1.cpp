#include <bits/stdc++.h>
using namespace std;
bool mark[500005], check[200005];
int su[50005], cnt = 0, a[200005], res[500005];
long long ans = 0;
vector<int> hav[200005];
void makesu() {
  for (int i = 2; i <= 500000; i++) {
    if (mark[i]) continue;
    su[++cnt] = i;
    for (int k = i + i; k <= 500000; k += i) mark[k] = 1;
  }
}
void make(int now) {
  int x = a[now];
  for (int i = 1; i <= cnt; i++) {
    if (1ll * su[i] * su[i] > x) break;
    if (x % su[i] == 0) {
      x /= su[i], hav[now].push_back(su[i]);
      while (x % su[i] == 0) x /= su[i];
      if (x == 1) break;
    }
  }
  if (x > 1) hav[now].push_back(x);
}
void add(int x) {
  int sz = hav[x].size();
  for (int i = 0; i < (1 << sz); i++) {
    int num = 1, bit = 0;
    for (int j = 0; j < sz; j++)
      if (i >> j & 1) bit++, num *= hav[x][j];
    if (bit & 1)
      ans -= res[num];
    else
      ans += res[num];
    res[num]++;
  }
}
void del(int x) {
  int sz = hav[x].size();
  for (int i = 0; i < (1 << sz); i++) {
    int num = 1, bit = 0;
    for (int j = 0; j < sz; j++)
      if (i >> j & 1) bit++, num *= hav[x][j];
    res[num]--;
    if (bit & 1)
      ans += res[num];
    else
      ans -= res[num];
  }
}
int main() {
  int n, m, i, k, j, x;
  makesu();
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), make(i);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    if (check[x])
      del(x), check[x] = 0;
    else
      add(x), check[x] = 1;
    cout << ans << endl;
  }
  return 0;
}
