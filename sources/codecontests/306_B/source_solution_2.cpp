#include <bits/stdc++.h>
using namespace std;
int d() {
  char c = getchar();
  int x = 0;
  while (c > '9' || c < '0') c = getchar();
  while (c <= '9' && c >= '0') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
const int N = 200010;
int n, m, a, k, bef[N * 10], num[N * 10], p, ans, o, w, maxn;
bool dust[N];
int main() {
  n = d();
  m = d();
  for (int i = 1; i <= m; i++) {
    a = d(), k = d();
    if (bef[a] < k)
      bef[a] = k, dust[num[a]] = 1, num[a] = i;
    else
      dust[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (bef[i] != 0)
      if (o == 0) {
        ans++;
        w = i;
        maxn = 0;
        for (i = w + 1; i <= w + bef[w] && i <= n; i++)
          if (i + bef[i] > w + bef[w] && i + bef[i] - 1 > o)
            o = bef[i] + i - 1, dust[num[maxn]] = 1, maxn = i;
          else
            dust[num[i]] = 1;
        i--;
        if (o != 0) ans++;
      } else {
        w = o;
        o = 0;
        maxn = 0;
        for (i = i; i <= w + 1 && i <= n; i++)
          if (i + bef[i] - 1 > w && i + bef[i] - 1 > o)
            o = i + bef[i] - 1, dust[num[maxn]] = 1, maxn = i;
          else
            dust[num[i]] = 1;
        i--;
        if (o != 0) ans++;
      }
  }
  printf("%d", m - ans);
  if (ans != m) {
    printf("\n");
    for (int i = 1; i <= m; i++)
      if (dust[i]) printf("%d ", i);
  }
  return 0;
}
