#include <bits/stdc++.h>
using namespace std;
int n, k;
template <class T>
ostream &operator<<(ostream &out, vector<T> v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
set<int> s[60];
vector<int> dfs(int level) {
  if (s[level].size() == 0 || level > 50) {
    vector<int> t;
    return t;
  }
  if (s[level].size() == 1 && abs(*s[level].begin()) == 1) {
    vector<int> t;
    t.push_back(*s[level].begin());
    return t;
  }
  int ok = 1;
  for (auto i : s[level])
    if (i % 2 != 0) ok = 0;
  if (ok) {
    s[level + 1].clear();
    for (auto i : s[level]) s[level + 1].insert(i / 2);
    vector<int> ans1 = dfs(level + 1);
    for (auto &i : ans1) i *= 2;
    return ans1;
  }
  s[level + 1].clear();
  for (auto i : s[level])
    if (i % 2) {
      int x = (i - 1) / 2;
      if (x) s[level + 1].insert(x);
    } else {
      s[level + 1].insert(i / 2);
    }
  vector<int> ans1 = dfs(level + 1);
  for (auto &i : ans1) i *= 2;
  ans1.push_back(1);
  s[level + 1].clear();
  for (auto i : s[level])
    if (i % 2) {
      int x = (i + 1) / 2;
      if (x) s[level + 1].insert(x);
    } else {
      s[level + 1].insert(i / 2);
    }
  vector<int> ans2 = dfs(level + 1);
  for (auto &i : ans2) i *= 2;
  ans2.push_back(-1);
  if (ans1.size() > ans2.size()) return ans2;
  return ans1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    if (k) s[1].insert(k);
  }
  cout << dfs(1) << '\n';
  return 0;
}
