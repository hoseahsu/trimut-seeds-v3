#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int a[maxn + 11], lmin[maxn + 11], lmax[maxn + 11], rmin[maxn + 11],
    rmax[maxn + 11];
int ans3[maxn + 11][5], ans4[maxn + 11][5];
set<int>::iterator it;
vector<int> v[maxn + 11];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    if (s.empty())
      lmin[i] = 0;
    else
      lmin[i] = s.top();
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    if (s.empty())
      lmax[i] = 0;
    else
      lmax[i] = s.top();
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    if (s.empty())
      rmin[i] = n + 1;
    else
      rmin[i] = s.top();
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    if (s.empty())
      rmax[i] = n + 1;
    else
      rmax[i] = s.top();
    s.push(i);
  }
  for (int i = 1; i <= n; i++) {
    int pos = max(rmin[i], rmax[i]);
    if (pos <= n) v[pos].emplace_back(i);
  }
  set<int> lef;
  lef.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) ans4[i][j] = ans4[i - 1][j];
    for (auto pos : v[i]) lef.insert(pos);
    v[i].clear();
    int pos = min(lmin[i], lmax[i]);
    it = lef.lower_bound(pos);
    if (it == lef.begin()) continue;
    it--;
    int x1 = *it;
    if (ans4[i][0] && x1 <= ans4[i][0]) continue;
    int x2 = a[rmax[x1]] > a[lmax[i]] ? rmax[x1] : lmax[i];
    int x3 = a[rmin[x1]] < a[lmin[i]] ? rmin[x1] : lmin[i];
    if (x2 > x3) swap(x2, x3);
    ans4[i][0] = x1;
    ans4[i][1] = x2;
    ans4[i][2] = x3;
    ans4[i][3] = i;
  }
  lef.clear();
  for (int i = 1; i <= n; i++)
    if (rmax[i] <= n) v[rmax[i]].emplace_back(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) ans3[i][j] = ans3[i - 1][j];
    for (auto pos : v[i]) lef.insert(pos);
    v[i].clear();
    int pos = lmax[i];
    it = lef.lower_bound(pos);
    if (it == lef.begin()) continue;
    it--;
    int x1 = *it;
    int x2 = a[rmax[x1]] > a[lmax[i]] ? rmax[x1] : lmax[i];
    ans3[i][0] = x1;
    ans3[i][1] = x2;
    ans3[i][2] = i;
  }
  lef.clear();
  for (int i = 1; i <= n; i++)
    if (rmin[i] <= n) v[rmin[i]].emplace_back(i);
  for (int i = 1; i <= n; i++) {
    if (ans3[i - 1][0] > ans3[i][0]) {
      for (int j = 0; j < 3; j++) ans3[i][j] = ans3[i - 1][j];
    }
    for (auto pos : v[i]) lef.insert(pos);
    v[i].clear();
    int pos = lmin[i];
    it = lef.lower_bound(pos);
    if (it == lef.begin()) continue;
    it--;
    int x1 = *it;
    int x2 = a[rmin[x1]] < a[lmin[i]] ? rmin[x1] : lmin[i];
    if (x1 > ans3[i][0]) {
      ans3[i][0] = x1;
      ans3[i][1] = x2;
      ans3[i][2] = i;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (ans4[r][0] >= l) {
      puts("4");
      for (int i = 0; i < 4; i++) printf("%d ", ans4[r][i]);
      puts("");
    } else if (ans3[r][0] >= l) {
      puts("3");
      for (int i = 0; i < 3; i++) printf("%d ", ans3[r][i]);
      puts("");
    } else
      puts("0");
  }
}
