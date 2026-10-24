#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100002;
const int MOD = 998244353;
const int MAGIC = 200;
const int MAX_BLOCK = MAX_N / MAGIC + 7;
const int INF = 1e9;
int n, k, prv[MAX_N], pos[MAX_N], a[MAX_N];
int nBlock, L[MAX_BLOCK], R[MAX_BLOCK], blockID[MAX_N];
int v[MAX_N], offset[MAX_BLOCK], head[MAX_BLOCK], ps[MAX_BLOCK][MAX_N];
int f[MAX_N];
vector<pair<int, int> > all, comp[MAX_BLOCK];
void readInput() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
}
void init() {
  for (int i = 1; i <= n; ++i) {
    prv[i] = pos[a[i]];
    pos[a[i]] = i;
  }
}
void sqrtDecompostion() {
  for (int i = 1; i <= n; ++i) {
    if (i % MAGIC == 1) {
      R[nBlock] = i - 1;
      L[++nBlock] = i;
    }
  }
  R[nBlock] = n;
  for (int i = 1; i <= nBlock; ++i) {
    for (int j = L[i]; j <= R[i]; ++j) blockID[j] = i;
  }
}
void upd(int idx, int l, int r, int delta) {
  for (int i = L[idx]; i <= R[idx]; ++i) {
    v[i] += offset[idx];
    if (l <= i && i <= r) v[i] += delta;
  }
  offset[idx] = 0;
  all.clear();
  comp[idx].clear();
  for (int i = L[idx]; i <= R[idx]; ++i) all.push_back({v[i], f[i - 1]});
  sort(all.begin(), all.end());
  comp[idx].push_back({-INF, 0});
  for (auto x : all) {
    if (x.first != comp[idx].back().first)
      comp[idx].push_back(x);
    else
      comp[idx].back().second = (comp[idx].back().second + x.second) % MOD;
  }
  for (int i = 1; i < comp[idx].size(); ++i)
    ps[idx][i] = (comp[idx][i].second + ps[idx][i - 1]) % MOD;
  for (int i = 0; i < comp[idx].size(); ++i) {
    if (comp[idx][i].first <= k) head[idx] = i;
  }
}
void upd(int l, int r, int delta) {
  if (l > r) return;
  if (blockID[l] == blockID[r]) return upd(blockID[l], l, r, delta);
  for (int i = blockID[l] + 1; i < blockID[r]; ++i) {
    offset[i] += delta;
    if (delta == -1) {
      while (head[i] + 1 < comp[i].size() &&
             comp[i][head[i] + 1].first + offset[i] <= k)
        ++head[i];
    } else {
      while (head[i] > 0 && comp[i][head[i]].first + offset[i] > k) --head[i];
    }
  }
  upd(l, R[blockID[l]], delta);
  upd(L[blockID[r]], r, delta);
}
int get() {
  int res = 0;
  for (int i = 1; i <= nBlock; ++i) res = (res + ps[i][head[i]]) % MOD;
  return res;
}
void solve() {
  for (int i = 1; i <= nBlock; ++i) upd(L[i], R[i], 0);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x1 = prv[i];
    int x2 = prv[x1];
    upd(x1 + 1, i, 1);
    upd(x2 + 1, x1, -1);
    f[i] = get();
    upd(L[blockID[i]], R[blockID[i]], 0);
  }
  cout << f[n];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  readInput();
  init();
  sqrtDecompostion();
  solve();
}
