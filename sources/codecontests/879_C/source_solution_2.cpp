#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-8;
const long double PI = acosl(-1.0);
int what[20][2];
vector<pair<int, int> > ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; i++) {
    what[i][0] = 0;
    what[i][1] = 1;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '&') {
      for (int j = 0; j < 10; j++) {
        what[j][0] &= ((x >> j) & 1);
        what[j][1] &= ((x >> j) & 1);
      }
    }
    if (c == '|') {
      for (int j = 0; j < 10; j++) {
        what[j][0] |= ((x >> j) & 1);
        what[j][1] |= ((x >> j) & 1);
      }
    }
    if (c == '^') {
      for (int j = 0; j < 10; j++) {
        what[j][0] ^= ((x >> j) & 1);
        what[j][1] ^= ((x >> j) & 1);
      }
    }
  }
  int x = 0;
  for (int j = 0; j < 10; j++) {
    if (!what[j][0] && !what[j][1]) x |= (1 << j);
  }
  if (x) {
    ans.push_back({0, x});
    ans.push_back({1, x});
  }
  x = 0;
  for (int j = 0; j < 10; j++) {
    if (what[j][0] && what[j][1]) x |= (1 << j);
  }
  if (x) ans.push_back({0, x});
  x = 0;
  for (int j = 0; j < 10; j++) {
    if (what[j][0] == 1 && what[j][1] == 0) x |= (1 << j);
  }
  if (x) ans.push_back({1, x});
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    if (ans[i].first)
      cout << '^';
    else
      cout << '|';
    cout << " " << ans[i].second << endl;
  }
  return 0;
}
