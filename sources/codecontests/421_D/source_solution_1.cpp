#include <bits/stdc++.h>
using namespace std;
int bit[300009];
int lowbit(int x) { return x & (-x); }
int n, m;
void treeAdd(int w, int val) {
  int i;
  for (i = w; i <= n; i += lowbit(i)) bit[i] += val;
}
int treeSum(int w) {
  int i, res = 0;
  for (i = w; i > 0; i -= lowbit(i)) res += bit[i];
  return res;
}
vector<int> a[300008];
int val[300008];
int zero;
void add(int t) {
  if (val[t] != 0)
    treeAdd(val[t], -1);
  else
    zero--;
  val[t]++;
  treeAdd(val[t], 1);
}
void del(int t) {
  treeAdd(val[t], -1);
  val[t]--;
  if (val[t] != 0)
    treeAdd(val[t], 1);
  else
    zero++;
}
int main() {
  memset(val, 0, sizeof(val));
  memset(bit, 0, sizeof(bit));
  scanf("%d%d", &n, &m);
  zero = n;
  long long ans = 0;
  for (int i = 0; i < 300007; i++) a[i].clear();
  for (int i = 0; i < n; i++) {
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    a[x1].push_back(x2);
    a[x2].push_back(x1);
    add(x1);
    add(x2);
  }
  for (int i = 1; i <= n; i++) {
    int len = a[i].size();
    for (int j = 0; j < len; j++) {
      del(a[i][j]);
    }
    if (len != 0)
      treeAdd(len, -1);
    else
      zero--;
    int de = m - len - 1;
    int tt = zero;
    if (de < 0)
      ans += (n - 1);
    else {
      if (de != 0) tt += treeSum(de);
      ans += (n - 1 - tt);
    }
    for (int j = 0; j < len; j++) {
      add(a[i][j]);
    }
    if (len != 0)
      treeAdd(len, 1);
    else
      zero++;
  }
  printf("%I64d\n", ans / 2);
}
