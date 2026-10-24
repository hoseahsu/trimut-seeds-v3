#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int maxn = 222222;
int a[maxn], n;
long long ans;
int mx[maxn][2], mi[maxn][2];
int sufmx[maxn][2], sufmi[maxn][2];
void dfs(int now, int x, int y) {
  if (now > n) return;
  x += dx[a[now - 1]];
  y += dy[a[now - 1]];
  mx[now][0] = max(mx[now - 1][0], x);
  mx[now][1] = max(mx[now - 1][1], y);
  mi[now][0] = min(mi[now - 1][0], x);
  mi[now][1] = min(mi[now - 1][1], y);
  sufmx[now][0] = x;
  sufmi[now][0] = x;
  sufmx[now][1] = y;
  sufmi[now][1] = y;
  if (now + 1 <= n) {
    dfs(now + 1, x, y);
    for (int i = 0; i < 2; i++) {
      sufmx[now][i] = max(sufmx[now][i], sufmx[now + 1][i]);
      sufmi[now][i] = min(sufmi[now][i], sufmi[now + 1][i]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        a[i] = 0;
      } else if (s[i] == 'S') {
        a[i] = 1;
      } else if (s[i] == 'A') {
        a[i] = 2;
      } else if (s[i] == 'D') {
        a[i] = 3;
      }
    }
    mx[0][0] = mx[0][1] = 0;
    mi[0][0] = mi[0][1] = 0;
    dfs(1, 0, 0);
    ans = (long long)(mx[n][1] - mi[n][1] + 1) * (mx[n][0] - mi[n][0] + 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        if (sufmx[i + 1][j] > sufmi[i + 1][j] || mx[i][j] > mi[i][j])
          if (sufmx[i + 1][j] > mx[i][j] && sufmi[i + 1][j] > mi[i][j]) {
            ans = min(ans, (long long)(sufmx[i + 1][j] - mi[i][j]) *
                               (mx[n][j ^ 1] - mi[n][j ^ 1] + 1));
          } else if (sufmx[i + 1][j] < mx[i][j] && sufmi[i + 1][j] < mi[i][j]) {
            ans = min(ans, (long long)(mx[i][j] - sufmi[i + 1][j]) *
                               (mx[n][j ^ 1] - mi[n][j ^ 1] + 1));
          }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
