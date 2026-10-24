#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, sz[N], b[N], cnt[N], pos[N];
vector<int> a[N], in[N];
bool have, vis[N], mark[N];
bool ok() {
  for (int i = 1; i <= n; i++) {
    pos[b[i]] = i;
  }
  for (int i = 1; i < n; i++) {
    int mn = n;
    for (auto& x : a[i]) {
      mn = min(mn, pos[x]);
      mark[x] = true;
    }
    bool now = true;
    for (int j = mn; j < mn + sz[i]; j++)
      if (!mark[b[j]]) now = false;
    if (!now) return false;
    for (auto& x : a[i]) mark[x] = false;
  }
  return true;
}
void check(int x, int y) {
  for (int i = 1; i <= n; i++) {
    vis[i] = false;
    cnt[i] = sz[i];
  }
  vis[x] = true;
  vis[y] = true;
  b[1] = x;
  b[2] = y;
  for (auto& id : in[x]) cnt[id]--;
  for (auto& id : in[y]) cnt[id]--;
  for (int i = 3; i <= n; i++) {
    int chose = -1;
    for (int j = 1; j < n; j++) {
      if (cnt[j] == 1) {
        if (chose != -1) return;
        for (auto& x : a[j])
          if (!vis[x]) chose = x;
      }
    }
    if (chose == -1) return;
    b[i] = chose;
    vis[chose] = true;
    for (auto& id : in[chose]) cnt[id]--;
  }
  if (ok()) {
    have = true;
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) in[i].clear();
  for (int i = 1; i < n; i++) {
    cin >> sz[i];
    a[i].resize(sz[i]);
    for (int j = 0; j < sz[i]; j++) {
      cin >> a[i][j];
      in[a[i][j]].push_back(i);
    }
  }
  have = false;
  for (int i = 1; i < n; i++) {
    if (have) break;
    if (sz[i] == 2) {
      check(a[i][0], a[i][1]);
      if (!have) check(a[i][1], a[i][0]);
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
