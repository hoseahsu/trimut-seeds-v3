#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char s[N][N];
int id[N][N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int scnt = 0;
  int ok = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') id[i][j] = ++scnt;
  int hh = 0, ss = 0;
  for (int i = 1; i <= n; i++) {
    int z = 0;
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#')
        cnt++;
      else {
        if (cnt > 0) z++;
        cnt = 0;
      }
    }
    if (cnt > 0) z++;
    if (z == 0) {
      ss = 1;
    }
    if (z > 1) {
      ok = 0;
      break;
    }
  }
  for (int j = 1; j <= m; j++) {
    int z = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i][j] == '#')
        cnt++;
      else {
        if (cnt > 0) z++;
        cnt = 0;
      }
    }
    if (cnt > 0) z++;
    if (z == 0) {
      hh = 1;
    }
    if (z > 1) {
      ok = 0;
      break;
    }
  }
  if (!ok)
    puts("-1");
  else if ((hh >= 1 && ss == 0) || (ss >= 1 && hh == 0))
    puts("-1");
  else {
    vector<int> fa(scnt + 1);
    int res = scnt;
    for (int i = 1; i <= scnt; i++) fa[i] = i;
    function<int(int)> find = [&](int x) {
      return fa[x] == x ? x : (fa[x] = find(fa[x]));
    };
    auto merge = [&](int x, int y) {
      x = find(x);
      y = find(y);
      if (x != y) fa[x] = y, res--;
    };
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (id[i][j])
          for (int t = 0; t < 4; t++) {
            int x = dx[t] + i;
            int y = dy[t] + j;
            if (id[x][y]) {
              merge(id[i][j], id[x][y]);
            }
          }
      }
    }
    cout << res << endl;
  }
}
