#include <bits/stdc++.h>
const long long inf = std::numeric_limits<long long>::max();
const long long mod = 1e9 + 7;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long aa[100100], nnow;
long long now;
long long all, a, b, h, w, n, sall;
int ans[2];
vector<pair<int, int> > v;
bool big(int u, int w) { return u > w; }
long long cc[40];
int solve(int i) {
  if (now * h >= a && w * (all / now) >= b) return 1;
  long long c = 1;
  int lasti = i;
  for (int j = i; j < nnow; j++) {
    if (j == i || aa[j] == aa[j - 1]) continue;
    c = aa[lasti];
    for (int u = 0; u < j - lasti + 1; u++) {
      now *= c;
      if (solve(j)) return 1;
      now /= c;
      c *= aa[lasti];
    }
    c = 1;
    lasti = j;
  }
  c *= aa[lasti];
  for (int u = 0; u < nnow - lasti; u++) {
    now *= c;
    if (solve(nnow)) return 1;
    now /= c;
    c *= aa[lasti];
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> h >> w >> n;
  for (int i = 0; i < n; i++) cin >> aa[i];
  sort(aa, aa + n, big);
  all = 1;
  now = 1;
  int last = 0;
  for (int i = 0; i < n; i++) {
    all *= aa[i];
    last = i;
    if (all >= 1e12) break;
  }
  sall = all;
  if (h >= a & w >= b) return cout << 0, 0;
  ans[0] = ans[1] = 100100;
  for (int i = last; i > -1; i--) {
    if (all < (a / h) * (b / w)) break;
    now = 1;
    nnow = i + 1;
    int c = solve(0);
    if (c == 0) break;
    ans[0] = min(i + 1, ans[0]);
    all /= aa[i];
  }
  swap(a, b);
  all = sall;
  if (h >= a & w >= b) return cout << 0, 0;
  for (int i = last; i > -1; i--) {
    if (all < (a / h) * (b / w)) break;
    now = 1;
    nnow = i + 1;
    int c = solve(0);
    if (c == 0) break;
    ans[1] = min(i + 1, ans[1]);
    all /= aa[i];
  }
  if (ans[0] >= 50 && ans[1] >= 50) {
    return cout << -1, 0;
  }
  cout << min(ans[0], ans[1]);
  return 0;
}
