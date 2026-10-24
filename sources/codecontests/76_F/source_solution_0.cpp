#include <bits/stdc++.h>
long long Left[101000], Right[101000];
int x[101000], t[101000], n, V, s[101000], p[101000], f[101000], L, R, MAX, Ans,
    Ans2;
bool cmp(int a, int b) {
  return Left[a] == Left[b] ? t[a] < t[b] : Left[a] < Left[b];
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; p[i] = i++) {
    scanf("%d%d", x + i, t + i);
    if (t[i] > MAX) MAX = t[i];
  }
  n++;
  scanf("%d", &V);
  for (i = 0; i < n; i++) {
    Left[i] = x[i] - 1ll * (MAX - t[i]) * V;
    Right[i] = x[i] + 1ll * (MAX - t[i]) * V;
  }
  std::sort(p, p + n, cmp);
  for (i = n - 1; i >= 0; i--) {
    L = 0;
    R = Ans + 1;
    for (; L + 1 < R;)
      if (Right[s[(L + R) / 2]] <= Right[p[i]])
        L = (L + R) / 2;
      else
        R = (L + R) / 2;
    if (!Ans || Right[s[L]] > Right[p[i]])
      f[p[i]] = 1;
    else
      f[p[i]] = f[s[L]] + 1;
    if (f[p[i]] > Ans) Ans = f[s[f[p[i]]] = p[i]];
    if (p[i] && f[p[i]] > Ans2) Ans2 = f[p[i]];
    if (Right[s[f[p[i]]]] > Right[p[i]]) s[f[p[i]]] = p[i];
  }
  printf("%d %d\n", f[0] - 1, Ans2);
  return 0;
}
