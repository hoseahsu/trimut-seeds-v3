#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int N, M, a[maxn], s[maxn], t;
bool f[maxn], g[maxn];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
    f[a[i]] = 1;
  }
  for (int i = 1; i < maxn; ++i) {
    if (f[i]) {
      if (!f[maxn - i]) {
        s[++M] = maxn - i;
      } else {
        ++t;
      }
    }
  }
  for (int i = 1; i < maxn && t; ++i) {
    if (!f[i] && !f[maxn - i]) {
      f[i] = 1;
      t -= 2;
      s[++M] = i;
      s[++M] = maxn - i;
    }
  }
  printf("%d\n", M);
  for (int i = 1; i <= M; ++i) {
    printf("%d ", s[i]);
  }
  return 0;
}
