#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int Mod = 1e9 + 7;
vector<pair<int, int> > ve1[maxn];
vector<int> ve2[maxn];
struct T {
  int sum, zr;
} tr[maxn * 4];
void push_up(int x) { tr[x].sum = (tr[x * 2].sum + tr[x * 2 + 1].sum) % Mod; }
void push_down(int x) {
  if (!tr[x].zr) return;
  tr[x * 2].zr = 1, tr[x * 2 + 1].zr = 1;
  tr[x * 2].sum = 0, tr[x * 2 + 1].sum = 0, tr[x].zr = 0;
}
int Search(int x, int sl, int sr, int l, int r) {
  if (sl > sr) return 0;
  if (sl <= l && sr >= r) return tr[x].sum;
  push_down(x);
  int ans = 0, mid = (l + r) / 2;
  if (sl <= mid) ans = (ans + Search(x * 2, sl, sr, l, mid)) % Mod;
  if (sr >= mid + 1) ans = (ans + Search(x * 2 + 1, sl, sr, mid + 1, r)) % Mod;
  return ans;
}
void zer(int x, int sl, int sr, int l, int r) {
  if (sl <= l && sr >= r) {
    tr[x].zr = 1, tr[x].sum = 0;
    return;
  }
  push_down(x);
  int mid = (l + r) / 2;
  if (sl <= mid) zer(x * 2, sl, sr, l, mid);
  if (sr >= mid + 1) zer(x * 2 + 1, sl, sr, mid + 1, r);
  push_up(x);
}
void modify(int x, int ke, int val, int l, int r) {
  if (l == r) {
    tr[x].sum = (tr[x].sum + val) % Mod;
    return;
  }
  push_down(x);
  int mid = (l + r) / 2;
  if (ke <= mid)
    modify(x * 2, ke, val, l, mid);
  else
    modify(x * 2 + 1, ke, val, mid + 1, r);
  push_up(x);
}
multiset<int> s;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a > b; }
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int xl, yl, xr, yr;
    scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
    ve1[xl].push_back(make_pair(yl, yr)), ve2[xr].push_back(yl);
  }
  s.insert(1), modify(1, 1, 1, 1, m);
  for (int i = 1; i <= n; i++) {
    sort(ve1[i].begin(), ve1[i].end(), cmp);
    if (i != 1) {
      for (int j = 0; j < ve1[i].size(); j++)
        if (ve1[i][j].second != m)
          modify(1, ve1[i][j].second + 1,
                 Search(1, *--s.upper_bound(ve1[i][j].second + 1),
                        ve1[i][j].second, 1, m),
                 1, m);
      for (int j = 0; j < ve2[i - 1].size(); j++)
        s.erase(s.find(ve2[i - 1][j]));
    }
    for (int j = 0; j < ve1[i].size(); j++)
      zer(1, ve1[i][j].first, ve1[i][j].second, 1, m),
          s.insert(ve1[i][j].first);
  }
  printf("%d", Search(1, *--s.upper_bound(m + 1), m, 1, m));
  return 0;
}
