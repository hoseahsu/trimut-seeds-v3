#include <bits/stdc++.h>
const int maxn = 3e5 + 50;
const int inf = 0x3f3f3f3f;
int n, f[2][312], cur = 0;
inline void Update(int& x, int y) { x = std::min(x, y); }
int main(int argc, char* argv[]) {
  scanf("%d", &n);
  memset(f[cur], 0x3f, sizeof(f[cur]));
  f[cur][0] = 0;
  while (n--) {
    int x, pre = cur;
    cur ^= 1;
    memset(f[cur], 0x3f, sizeof(f[cur]));
    scanf("%d", &x);
    for (int i = 0; i < 312; ++i)
      if (f[pre][i] != inf) {
        if (i + x / 100 < 312) Update(f[cur][i + x / 100], f[pre][i] + x);
        int used = std::min(x, i * 10);
        if (i - used / 10 < 312)
          Update(f[cur][i - used / 10], f[pre][i] + x - used);
      }
  }
  int ans = inf;
  for (int i = 0; i < 312; ++i) ans = std::min(ans, f[cur][i]);
  printf("%d\n", ans);
  return 0;
}
