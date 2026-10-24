#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, k;
  cin >> n >> t >> k;
  vector<int> a;
  map<int, int> mp;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    mp[x]++;
    a.push_back(x);
  }
  mp[0]++;
  bool ok = 1;
  vector<pair<int, int> > ans;
  map<int, vector<int> > lvl;
  lvl[0].push_back(1);
  int cnt = 2;
  for (int i = 1; i <= t; i++) {
    if (!lvl.count(i - 1)) {
      cout << "-1" << endl;
      return 0;
    }
    for (int o = 1; o <= a[i - 1]; o++) {
      lvl[i].push_back(cnt++);
    }
  }
  int c = 0;
  for (int i = 0; i + 1 <= t; i++) {
    ans.push_back({lvl[i][0], lvl[i + 1][0]});
    c += a[i] - 1;
  }
  k -= a[t - 1];
  c -= k;
  c -= a[t - 1] - 1;
  if (c < 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i + 1 <= t; i++) {
    int pp = 1;
    for (int o = 1; o < lvl[i].size() && c > 0; o++) {
      if (pp < lvl[i + 1].size()) {
        ans.push_back({lvl[i + 1][pp], lvl[i][o]});
        c--;
        pp++;
      }
    }
    while (pp != lvl[i + 1].size()) {
      ans.push_back({lvl[i][0], lvl[i + 1][pp++]});
    }
  }
  if (c > 0) {
    cout << "-1" << endl;
    return 0;
  }
  cout << n << endl;
  for (pair<int, int> p : ans) {
    cout << p.first << " " << p.second << endl;
  }
}
