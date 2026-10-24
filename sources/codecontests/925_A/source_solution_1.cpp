#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int base = 1e9;
const int MAX = 2e5;
const long double EPS = 1e-10;
const long double PI = acos(-1.);
int n, m;
int D, E, v;
int d[MAX];
int e[MAX];
int x1, x2, adlsdss, y2;
int drab() {
  int cur = INF;
  int pos = lower_bound(d, d + D, adlsdss) - d;
  if (pos < D) {
    cur = min(cur, abs(adlsdss - d[pos]) + abs(y2 - d[pos]) + abs(x1 - x2));
  }
  pos--;
  if (pos >= 0) {
    cur = min(cur, abs(adlsdss - d[pos]) + abs(y2 - d[pos]) + abs(x1 - x2));
  }
  return cur;
}
int lift() {
  int cur = INF;
  int pos = lower_bound(e, e + E, adlsdss) - e;
  if (pos < E) {
    cur = min(cur, abs(adlsdss - e[pos]) + abs(y2 - e[pos]) +
                       (abs(x1 - x2) + v - 1) / v);
  }
  pos--;
  if (pos >= 0) {
    cur = min(cur, abs(adlsdss - e[pos]) + abs(y2 - e[pos]) +
                       (abs(x1 - x2) + v - 1) / v);
  }
  return cur;
}
int solve() {
  int best = INF;
  if (x1 == x2) {
    return abs(adlsdss - y2);
  }
  if (D) {
    best = min(best, drab());
  }
  if (E) {
    best = min(best, lift());
  }
  return best;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> D >> E >> v;
  for (int i = (0); i < (D); ++i) {
    cin >> d[i];
  }
  for (int j = (0); j < (E); ++j) {
    cin >> e[j];
  }
  int q;
  cin >> q;
  for (int i = (0); i < (q); ++i) {
    cin >> x1 >> adlsdss >> x2 >> y2;
    cout << solve() << endl;
  }
  return 0;
}
