#include <bits/stdc++.h>
using namespace std;
pair<int, int> op[100005];
int n, a, b;
vector<pair<int, pair<int, int> > > ans;
bool row[100005];
bool col[100005];
int step;
void chg_row(int x, int y) {
  ans.push_back(make_pair(1, make_pair(x, y)));
  ++step;
  for (int i = 0; i < n; ++i)
    if (op[i].first == x)
      op[i].first = y;
    else if (op[i].first == y)
      op[i].first = x;
}
void chg_col(int x, int y) {
  ans.push_back(make_pair(2, make_pair(x, y)));
  ++step;
  for (int i = 0; i < n - 1; ++i)
    if (op[i].second == x)
      op[i].second = y;
    else if (op[i].second == y)
      op[i].second = x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    op[i] = make_pair(a, b);
    col[b] = true;
  }
  for (int i = 1, j = 2; i <= n && j <= n; ++i, ++j) {
    if (col[i] == false) {
      for (; j <= n && col[j] == false; ++j)
        ;
      if (j != n + 1) {
        chg_col(i, j);
        col[i] = true;
        col[j] = false;
      }
    }
  }
  int base = n;
  for (int i = n - 1; i >= 0; --i) {
    if (col[i]) {
      for (int j = 0; j < n - 1; ++j) {
        if (op[j].second == i && row[op[j].first] == false) {
          if (op[j].first != base) chg_row(op[j].first, base);
          --base;
          row[op[j].first] = true;
        }
      }
    }
  }
  cout << step << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second.first << " "
         << ans[i].second.second << endl;
  }
}
