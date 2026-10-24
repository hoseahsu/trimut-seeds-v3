#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
bool vis[maxn * 2][1 << 20];
int f[maxn * 2][1 << 20], mask[maxn * 2][26], n;
char mat[maxn][maxn];
int dfs(int i, int s, int now, bool flag) {
  if (vis[i][s]) return f[i][s];
  vis[i][s] = true;
  int &ret = f[i][s];
  ret = -1e9;
  if (i == 2 * n - 2)
    ret = 0;
  else {
    for (int(nxt) = (0); (nxt) <= ((26) - 1); (nxt)++) {
      int ns = mask[i + 1][nxt] & (s | (s << 1));
      if (ns) ret = max(ret, -dfs(i + 1, ns, nxt, !flag));
    }
  }
  if (flag) {
    if (now == 0)
      ret++;
    else if (now == 1)
      ret--;
  } else {
    if (now == 0)
      ret--;
    else if (now == 1)
      ret++;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) <= ((n)-1); (i)++) scanf("%s", mat[i]);
  for (int(i) = (0); (i) <= ((2 * n) - 1); (i)++)
    for (int(j) = (0); (j) <= ((26) - 1); (j)++)
      for (int(k) = (0); (k) <= ((n)-1); (k)++) {
        int x = k, y = i - k;
        if (y >= 0 && y < n && mat[x][y] == j + 'a') mask[i][j] |= 1 << k;
      }
  int ans = dfs(0, 1, mat[0][0] - 'a', false);
  if (ans < 0)
    puts("FIRST");
  else if (ans > 0)
    puts("SECOND");
  else
    puts("DRAW");
}
