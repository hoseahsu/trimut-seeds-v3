#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
int x[maxn], y[maxn], c[maxn], d[maxn], a[maxn], b[maxn];
vector<long long> v;
void move(int j) {
  int dx = c[j] - a[j];
  int dy = d[j] - b[j];
  c[j] = a[j] - dy;
  d[j] = b[j] + dx;
}
bool check() {
  v.clear();
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      v.push_back((c[i] - c[j]) * 1ll * (c[i] - c[j]) +
                  (d[i] - d[j]) * 1ll * (d[i] - d[j]));
  sort(v.begin(), v.end());
  return (v[0] > 0 && v[0] == v[1] && v[1] == v[2] && v[2] == v[3] &&
          v[4] == v[3] * 2 && v[5] == v[4]);
}
int main() {
  int INF = 222;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int ans = INF;
    for (int j = 0; j < 4; j++) cin >> x[j] >> y[j] >> a[j] >> b[j];
    for (int mask = 0; mask < 256; mask++) {
      int kol = 0;
      for (int j = 0; j < 4; j++) c[j] = x[j], d[j] = y[j];
      for (int j = 0; j < 4; j++) {
        int xx = mask & (3 << j * 2);
        xx >>= j * 2;
        kol += xx;
        for (int g = 0; g < xx; g++) move(j);
      }
      if (check()) {
        ans = min(ans, kol);
      }
    }
    if (ans == INF)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
  cin >> n;
  return 0;
}
