#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int MAXM = 255;
int n, m;
int cnt[MAXN];
int x[MAXM];
int y[MAXM];
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); ++i) scanf("%d%d", x + i, y + i);
  for (int i = (1); i < (n + 1); ++i) cnt[i] = 1;
  for (int i = (0); i < (m); ++i)
    for (int j = (0); j < (m); ++j) {
      if (i == j) continue;
      if (y[i] == y[j]) continue;
      long long a = y[i] - y[j];
      long long b = x[j] - x[i];
      long long c = -(a * x[i] + b * y[i]);
      if (abs(c) % abs(a) != 0) continue;
      long long X = -c / a;
      if (X < 1 || X > n) continue;
      int ccnt = 0;
      for (int k = (0); k < (m); ++k)
        if (a * x[k] + b * y[k] + c == 0) ++ccnt;
      cnt[X] = max(cnt[X], ccnt);
    }
  long long sol = 0;
  for (int i = (1); i < (n + 1); ++i) sol += cnt[i];
  printf("%lld\n", sol);
  return 0;
}
