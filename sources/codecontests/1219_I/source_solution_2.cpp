#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n)), b(n, vector<int>(n));
  for (int i = 0; i < (int)(n); ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)(n); ++j) {
      a[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < (int)(n); ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)(n); ++j) {
      b[i][j] = s[j] - '0';
    }
  }
  vector<int> v(n);
  string s;
  cin >> s;
  for (int i = 0; i < (int)(n); ++i) v[i] = s[i] - '0';
  int c = -1;
  for (int i = 0; i < (int)(n); ++i) {
    if (v[i] == 1) {
      c = i;
    }
  }
  if (c == -1) {
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(n); ++j) {
        if (a[i][j] != b[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
    cout << 0 << endl;
    return 0;
  }
  vector<pair<int, int> > res, res2;
  vector<vector<int> > d = a;
  res.push_back(make_pair(0, c));
  for (int i = 0; i < (int)(n); ++i) {
    d[c][i] ^= v[i];
  }
  for (int i = 0; i < (int)(n); ++i) {
    if (d[c][i] != b[c][i]) {
      res.push_back(make_pair(1, i));
      for (int j = 0; j < (int)(n); ++j) {
        d[j][i] ^= v[j];
      }
    }
  }
  bool ng = 0;
  for (int i = 0; i < (int)(n); ++i) {
    bool flag = 0;
    for (int j = 0; j < (int)(n); ++j) {
      if (d[i][j] != b[i][j]) {
        flag = 1;
      }
    }
    if (flag) {
      res.push_back(make_pair(0, i));
      for (int j = 0; j < (int)(n); ++j) {
        d[i][j] ^= v[j];
      }
      for (int j = 0; j < (int)(n); ++j) {
        if (d[i][j] != b[i][j]) {
          ng = 1;
        }
      }
    }
    if (ng) break;
  }
  if (!ng) {
    cout << res.size() << "\n";
    for (auto x : res) {
      if (x.first == 0) {
        cout << "row " << x.second << "\n";
      } else {
        cout << "col " << x.second << "\n";
      }
    }
    return 0;
  }
  d = a;
  for (int i = 0; i < (int)(n); ++i) {
    if (d[c][i] != b[c][i]) {
      res.push_back(make_pair(1, i));
      for (int j = 0; j < (int)(n); ++j) {
        d[j][i] ^= v[j];
      }
    }
  }
  ng = 0;
  for (int i = 0; i < (int)(n); ++i) {
    bool flag = 0;
    for (int j = 0; j < (int)(n); ++j) {
      if (d[i][j] != b[i][j]) {
        flag = 1;
      }
    }
    if (flag) {
      res.push_back(make_pair(0, i));
      for (int j = 0; j < (int)(n); ++j) {
        d[i][j] ^= v[j];
      }
      for (int j = 0; j < (int)(n); ++j) {
        if (d[i][j] != b[i][j]) {
          ng = 1;
        }
      }
    }
    if (ng) break;
  }
  if (!ng) {
    cout << res.size() << "\n";
    for (auto x : res) {
      if (x.first == 0) {
        cout << "row " << x.second << "\n";
      } else {
        cout << "col " << x.second << "\n";
      }
    }
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
