#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7, mod = 1e9 + 9, pw = 31;
const double eps = 1e-11;
map<pair<int, int>, int> m;
pair<int, int> ans = make_pair(-INF, -INF), check;
int n, d[30][5];
vector<int> res;
void out() {
  for (auto i : res) {
    if (i == 1) cout << "MW";
    if (i == 2) cout << "LW";
    if (i == 3) cout << "LM";
    cout << "\n";
  }
}
void rec1(int n, int v = 0, int a = 0, int b = 0, int c = 0) {
  if (v == n) {
    if (!m.count(make_pair(a - b, b - c)) || m[make_pair(a - b, b - c)] < c) {
      m[make_pair(a - b, b - c)] = c;
    }
    return;
  }
  rec1(n, v + 1, a, b + d[v + 1][2], c + d[v + 1][3]);
  rec1(n, v + 1, a + d[v + 1][1], b, c + d[v + 1][3]);
  rec1(n, v + 1, a + d[v + 1][1], b + d[v + 1][2], c);
}
void rec2(int n, int v = 0, int a = 0, int b = 0, int c = 0) {
  if (v == n) {
    if (m.count(make_pair(b - a, c - b)) &&
        m[make_pair(b - a, c - b)] + c > ans.first + ans.second) {
      check = make_pair(b - a, c - b);
      ans = make_pair(m[check], c);
    }
    return;
  }
  rec2(n, v + 1, a, b + d[v + 1][2], c + d[v + 1][3]);
  rec2(n, v + 1, a + d[v + 1][1], b, c + d[v + 1][3]);
  rec2(n, v + 1, a + d[v + 1][1], b + d[v + 1][2], c);
}
bool ok = 0;
void find1(int n, int v = 0, int a = 0, int b = 0, int c = 0) {
  if (ok) return;
  if (v == n) {
    if (make_pair(a - b, b - c) == check && c == ans.first) {
      out();
      ok = 1;
    }
    return;
  }
  res.push_back(1);
  find1(n, v + 1, a, b + d[v + 1][2], c + d[v + 1][3]);
  res.pop_back();
  res.push_back(2);
  find1(n, v + 1, a + d[v + 1][1], b, c + d[v + 1][3]);
  res.pop_back();
  res.push_back(3);
  find1(n, v + 1, a + d[v + 1][1], b + d[v + 1][2], c);
  res.pop_back();
}
void find2(int n, int v = 0, int a = 0, int b = 0, int c = 0) {
  if (v == n) {
    if (make_pair(b - a, c - b) == check && c == ans.second) {
      out();
      exit(0);
    }
    return;
  }
  res.push_back(1);
  find2(n, v + 1, a, b + d[v + 1][2], c + d[v + 1][3]);
  res.pop_back();
  res.push_back(2);
  find2(n, v + 1, a + d[v + 1][1], b, c + d[v + 1][3]);
  res.pop_back();
  res.push_back(3);
  find2(n, v + 1, a + d[v + 1][1], b + d[v + 1][2], c);
  res.pop_back();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) cin >> d[i][j];
  }
  rec1(n / 2);
  rec2(n, n / 2);
  if (ans == make_pair(-INF, -INF)) {
    cout << "Impossible";
    return 0;
  }
  find1(n / 2);
  res.resize(0);
  find2(n, n / 2);
  return 0;
}
