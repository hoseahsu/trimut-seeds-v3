#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int pri[maxn], x2, x1, mp, mn = 0x3f3f3f3f;
bool vis[maxn];
void prime(int N) {
  for (register int i = 2; i <= N; ++i) {
    if (!vis[i]) pri[++pri[0]] = i;
    for (register int j = 1; j <= pri[0] && i * pri[j] <= N; ++j) {
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
int GetMP(int x) {
  if (!vis[x]) return -0x3f3f3f3f;
  int x1 = 1, x2 = x;
  for (register int i = 2; i <= x; ++i) {
    x1 = i;
    while (x % i == 0) x /= i;
  }
  return x1;
}
int main() {
  prime(1e6);
  scanf("%d", &x2), x1 = x2 - GetMP(x2);
  for (register int i = (x1 + 1); i <= x2; ++i) {
    mn = min(i - (mp = GetMP(i)) + 1, mn);
    if (i / mp == 2) break;
  }
  printf("%d", mn);
  return 0;
}
