#include <bits/stdc++.h>
using namespace std;
int w[500010], c[500010], a[500010], day;
long long ans;
double dot;
void qsort(int l, int r, int s) {
  int first = (l + r) >> 1;
  int i = l, j = r, m = c[first] - day * a[first], v = w[first];
  if (l == r) {
    long long sum = m * 1LL * s;
    ans += sum / v;
    dot += (sum % v) * 1. / v;
    return;
  }
  while (i <= j) {
    while ((c[i] - day * a[i]) * 1LL * v < w[i] * 1LL * m) i++;
    while ((c[j] - day * a[j]) * 1LL * v > w[j] * 1LL * m) j--;
    if (i <= j) {
      swap(c[i], c[j]);
      swap(w[i], w[j]);
      swap(a[i], a[j]);
      i++, j--;
    }
  }
  j = max(j, l);
  long long sum = 0, cnt = 0;
  for (int k = l; k <= j; k++) cnt += c[k] - day * a[k], sum += w[k];
  if (sum >= s)
    qsort(l, j, s);
  else
    ans += cnt, qsort(j + 1, r, s - sum);
}
int main() {
  int i, j, k, h, t;
  int n, m, s;
  while (~scanf("%d%d%d", &n, &m, &s)) {
    for (i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (i = 1; i <= m; i++) scanf("%d", &c[i]);
    for (i = 1; i <= m; i++) scanf("%d", &a[i]);
    ans = 0;
    dot = 0;
    for (day = 0; day < n; day++) {
      qsort(1, m, s);
      ans += (int)dot;
      dot -= (int)dot;
    }
    char buff[20];
    sprintf(buff, "%.15lf", dot);
    printf("%I64d%s\n", ans, buff + 1);
  }
  return 0;
}
